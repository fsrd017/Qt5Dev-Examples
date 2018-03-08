#include "svgwidget.h"

SvgWidget::SvgWidget(QWidget *parent):QSvgWidget(parent)
{
    render =renderer();
}

void SvgWidget::wheelEvent(QWheelEvent *e)
{
    const double diff=0.1;						//(a)
    QSize size =render->defaultSize();			//(b)
    int width =size.width();
    int height =size.height();
    if(e->delta()>0) 							//(c)
    {
       //对图片的长、宽值进行处理，放大一定的比例
       width =int(this->width()+this->width()*diff);
       height =int(this->height()+this->height()*diff);
    }
    else
    {
       //对图片的长、宽值进行处理，缩小一定的比例
       width =int(this->width()-this->width()*diff);
       height =int(this->height()-this->height()*diff);
    }
    resize(width,height);	//利用新的长、宽值对图片进行resize()操作
}
