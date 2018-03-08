#ifndef LANGSWITCH_H
#define LANGSWITCH_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
class LangSwitch : public QWidget
{
    Q_OBJECT

public:
    LangSwitch(QWidget *parent = 0);
    ~LangSwitch();
private slots:
     void changeLang(int index);		//(a)
private:
     void createScreen();				//(b)
     void changeTr(const QString& langCode);
     void refreshLabel();
     QComboBox* combo;					//界面中可以看见的下拉菜单
     QLabel* label;						//界面中可以看见的标签
};

#endif // LANGSWITCH_H
