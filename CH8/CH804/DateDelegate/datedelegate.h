#ifndef DATEDELEGATE_H
#define DATEDELEGATE_H

#include <QItemDelegate>
class DateDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    DateDelegate(QObject *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem & option, const QModelIndex &index) const;			//(a)
    void setEditorData(QWidget *editor, const QModelIndex &index) const;													//(b)
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;	//将Delegate中对数据的改变更新至Model中
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem & option, const QModelIndex &index) const;		//更新控件区的显示
};

#endif // DATEDELEGATE_H
