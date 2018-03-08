#ifndef THREADDLG_H
#define THREADDLG_H

#include <QDialog>
#include <QPushButton>
#include "workthread.h"
#define MAXSIZE 5							//MAXSIZE宏定义了线程的数目
class ThreadDlg : public QDialog
{
    Q_OBJECT

public:
    ThreadDlg(QWidget *parent = 0);
    ~ThreadDlg();
private:
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QPushButton *quitBtn;
    WorkThread *workThread[MAXSIZE];		//(a)
public slots:
    void slotStart();						//槽函数用于启动线程
    void slotStop();						//槽函数用于终止线程
};

#endif // THREADDLG_H
