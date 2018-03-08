#include "mouseevent.h"

MouseEvent::MouseEvent(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("鼠标事件"));					//设置窗体的标题
    statusLabel = new QLabel;						//(a)
    statusLabel->setText(tr("当前位置："));
    statusLabel->setFixedWidth(100);
    MousePosLabel = new QLabel;						//(b)
    MousePosLabel->setText(tr(""));
    MousePosLabel->setFixedWidth(100);
    statusBar()->addPermanentWidget(statusLabel);	//(c)
    statusBar()->addPermanentWidget(MousePosLabel);
    this->setMouseTracking(true);					//(d)
    resize(400,200);
}

void MouseEvent::mousePressEvent(QMouseEvent *e)
{
    QString str="("+QString::number(e->x())+","+QString::number(e->y()) +")";														//(a)
    if(e->button()==Qt::LeftButton)
    {
        statusBar()->showMessage(tr("左键：")+str);
    }
    else if(e->button()==Qt::RightButton)
    {
        statusBar()->showMessage(tr("右键：")+str);
    }
    else if(e->button()==Qt::MidButton)
    {
        statusBar()->showMessage(tr("中键：")+str);
    }
}

void MouseEvent::mouseMoveEvent(QMouseEvent *e)
{
    MousePosLabel->setText("("+QString::number(e->x())+","+QString::number(e->y())+")");
}

void MouseEvent::mouseReleaseEvent(QMouseEvent *e)
{
    QString str="("+QString::number(e->x())+","+QString::number(e->y()) +")";
    statusBar()->showMessage(tr("释放在：")+str,3000);
}

void MouseEvent::mouseDoubleClickEvent(QMouseEvent *e){}

MouseEvent::~MouseEvent()
{

}
