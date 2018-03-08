#include "butterfly.h"
#include <math.h>
const static double PI=3.1416;
Butterfly::Butterfly(QObject *parent) : QObject(parent)
{
    up = true;					//给标志蝴蝶翅膀位置的变量赋初值
    pix_up.load("up.png");		//调用QPixmap的load()函数加载所用到的图片
    pix_down.load("down.png");
    startTimer(100);			//启动定时器，并设置时间间隔为100毫秒
}
QRectF Butterfly::boundingRect() const
{
    qreal adjust =2;
    return QRectF(-pix_up.width()/2-adjust,-pix_up.height()/2-adjust,
                  pix_up.width()+adjust*2,pix_up.height()+adjust*2);
}
void Butterfly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(up)
    {
        painter->drawPixmap(boundingRect().topLeft(),pix_up);
        up=!up;
    }
    else
    {
        painter->drawPixmap(boundingRect().topLeft(),pix_down);
        up=!up;
    }
}
void Butterfly::timerEvent(QTimerEvent *)
{
    //边界控制
    qreal edgex=scene()->sceneRect().right()+boundingRect().width()/2;
                                                //限定蝴蝶飞舞的右边界
    qreal edgetop=scene()->sceneRect().top()+boundingRect(). height()/2;														//限定蝴蝶飞舞的上边界
    qreal edgebottom=scene()->sceneRect().bottom()+boundingRect(). height()/2;											//限定蝴蝶飞舞的下边界
    if(pos().x()>=edgex)			//若超过了右边界，则水平移回左边界处
        setPos(scene()->sceneRect().left(),pos().y());
    if(pos().y()<=edgetop)			//若超过了上边界，则垂直移回下边界处
        setPos(pos().x(),scene()->sceneRect().bottom());
    if(pos().y()>=edgebottom)		//若超过了下边界，则垂直移回上边界处
        setPos(pos().x(),scene()->sceneRect().top());
    angle+=(qrand()%10)/20.0;
    qreal dx=fabs(sin(angle*PI)*10.0);
    qreal dy=(qrand()%20)-10.0;
    setPos(mapToParent(dx,dy));		//(a)
}
