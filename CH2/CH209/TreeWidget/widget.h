#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void init();
    void updateParentItem(QTreeWidgetItem* item);
public slots:
    void treeItemChanged(QTreeWidgetItem* item, int column);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
