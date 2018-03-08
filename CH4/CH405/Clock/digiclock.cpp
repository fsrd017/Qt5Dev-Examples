#include "digiclock.h"
#include <QTimer>
#include <QTime>
#include <QMouseEvent>
DigiClock::DigiClock(QWidget *parent):QLCDNumber(parent)
{
    /* 设置时钟背景 */								//(a)
     QPalette p=palette();
     p.setColor(QPalette::Window,Qt::blue);
     setPalette(p);
     setWindowFlags(Qt::FramelessWindowHint);	//(b)
     setWindowOpacity(0.5);						//(c)
     QTimer *timer=new QTimer(this);			//新建一个定时器对象
     connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));	//(d)
     timer->start(1000);						//(e)
     showTime();								//初始时间显示
     resize(150,60);							//设置电子时钟显示的尺寸
     showColon=true;                            //初始化
}

void DigiClock::showTime()
{
    QTime time=QTime::currentTime();			//(a)
    QString text=time.toString("hh:mm");		//(b)
    if(showColon)								//(c)
    {
        text[2]=':';
        showColon=false;
    }
    else
    {
        text[2]=' ';
        showColon=true;
    }
    display(text);								//显示转换好的字符串时间
}

void DigiClock::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        dragPosition=event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    if(event->button()==Qt::RightButton)
    {
        close();
    }
}

void DigiClock::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        move(event->globalPos()-dragPosition);
        event->accept();
    }
}


