#include "keyevent.h"
#include <QPainter>
KeyEvent::KeyEvent(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("键盘事件"));
    setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window,Qt::white);
    setPalette(palette);
    setMinimumSize(512,256);
    setMaximumSize(512,256);
    width=size().width();
    height=size().height();
    pix = new QPixmap(width,height);
    pix->fill(Qt::white);
    image.load("../image/image.png");
    startX=100;
    startY=100;
    step=20;
    drawPix();
    resize(512,256);
}

void KeyEvent::drawPix()
{
    pix->fill(Qt::white);				//重新刷新pix对象为白色底色
    QPainter *painter = new QPainter;	//创建一个QPainter对象
    QPen pen(Qt::DotLine);				//(a)
    for(int i=step;i<width;i=i+step)	//按照步进值的间隔绘制纵向的网格线
    {
        painter->begin(pix);			//指定pix为绘图设备
        painter->setPen(pen);
        painter->drawLine(QPoint(i,0),QPoint(i,height));
        painter->end();
    }
    for(int j=step;j<height;j=j+step)	//按照步进值的间隔绘制横向的网格线
    {
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(0,j),QPoint(width,j));
        painter->end();
    }
    painter->begin(pix);
    painter->drawImage(QPoint(startX,startY),image);	//(b)
    painter->end();
}

void KeyEvent::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers()==Qt::ControlModifier)			//(a)
    {
        if(event->key()==Qt::Key_Left)					//(b)
        {
            startX=(startX-1<0)?startX:startX-1;
        }
        if(event->key()==Qt::Key_Right)					//(c)
        {
            startX=(startX+1+image.width()>width)?startX:startX+1;
        }
        if(event->key()==Qt::Key_Up)						//(d)
        {
            startY=(startY-1<0)?startY:startY-1;
        }
        if(event->key()==Qt::Key_Down)					//(e)
        {
            startY=(startY+1+image.height()>height)?startY:startY+1;
        }
    }
    else								//对【Ctrl】键没有按下的处理
    {
        /* 首先调节图标左上顶点的位置至网格的顶点上 */
        startX=startX-startX%step;
        startY=startY-startY%step;
        if(event->key()==Qt::Key_Left)					//(f)
        {
            startX=(startX-step<0)?startX:startX-step;
        }
        if(event->key()==Qt::Key_Right)					//(g)
        {
            startX=(startX+step+image.width()>width)?startX:startX+step;
        }
        if(event->key()==Qt::Key_Up)						//(h)
        {
            startY=(startY-step<0)?startY:startY-step;
        }
        if(event->key()==Qt::Key_Down)					//(i)
        {
            startY=(startY+step+image.height()>height)?
            startY:startY+step;
        }
        if(event->key()==Qt::Key_Home)					//(j)
        {
            startX=0;
            startY=0;
        }
        if(event->key()==Qt::Key_End)					//(k)
        {
            startX=width-image.width();
            startY=height-image.height();
        }
    }
    drawPix();		//根据调整后的图标位置重新在pix中绘制图像
    update();		//触发界面重画
}

void KeyEvent::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(QPoint(0,0),*pix);
    painter.end();
}

KeyEvent::~KeyEvent()
{

}
