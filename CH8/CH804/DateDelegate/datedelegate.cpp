#include "datedelegate.h"
#include <QDateTimeEdit>
DateDelegate::DateDelegate(QObject *parent):QItemDelegate(parent)
{

}
QWidget *DateDelegate::createEditor(QWidget *parent,const QStyleOptionViewItem &/*option*/,const QModelIndex &/*index*/) const
{
    QDateTimeEdit *editor = new QDateTimeEdit(parent);		//(a)
    editor->setDisplayFormat("yyyy-MM-dd");					//(b)
    editor->setCalendarPopup(true);							//(c)
    editor->installEventFilter(const_cast<DateDelegate*>(this));
                                                            //(d)
    return editor;
}
void DateDelegate::setEditorData(QWidget *editor,const QModelIndex &index) const
{
   QString dateStr= index.model()->data(index).toString();	//(a)
   QDate date = QDate::fromString(dateStr,Qt::ISODate);		//(b)
   QDateTimeEdit *edit=static_cast<QDateTimeEdit*>(editor);	//(c)
   edit->setDate(date);                                     //设置控件的显示数据
}
void DateDelegate::setModelData(QWidget *editor,QAbstractItemModel *model, const QModelIndex &index) const
{
    QDateTimeEdit *edit=static_cast<QDateTimeEdit*>(editor);//(a)
    QDate date = edit->date();								//(b)
    model->setData(index,QVariant(date.toString(Qt::ISODate)));//(c)
}
void DateDelegate::updateEditorGeometry(QWidget *editor,const QStyleOptionViewItem &option,const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
