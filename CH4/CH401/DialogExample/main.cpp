#include "dialog.h"
#include <QApplication>
//#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QTextCodec::setCodecForLocale(setCodecForTr(QTextCodec::codecForLocale());
    Dialog w;
    w.show();

    return a.exec();
}
