#include "flashitem.h"

FlashItem::FlashItem(QObject *parent) : QObject(parent)
{
    flash=true;					//为颜色切换标识赋初值
    setFlag(ItemIsMovable);     //(a)
    startTimer(1000);			//启动一个定时器，以1000毫秒为时间间隔
}
QRectF FlashItem::boundingRect() const
{
    qreal adjust = 2;
    return QRectF(-10-adjust,-10-adjust,43+adjust,43+adjust);
}
void FlashItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);         //闪烁图元的阴影区不绘制边线
    painter->setBrush(Qt::darkGray);    //闪烁图元的阴影区的阴影画刷颜色为深灰
    painter->drawEllipse(-7,-7,40,40);	//绘制阴影区
    painter->setPen(QPen(Qt::black,0));
    //闪烁区的椭圆边线颜色为黑色、线宽为0
    painter->setBrush(flash?(Qt::red):(Qt::yellow));	//(a)
    painter->drawEllipse(-10,-10,40,40);				//(b)
}
void FlashItem::timerEvent(QTimerEvent *)
{
    flash=!flash;
    update();
}
