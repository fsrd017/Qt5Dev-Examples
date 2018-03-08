#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap("Qt.png");				//(a)
    QSplashScreen splash(pixmap);			//(b)
    splash.show();							//显示此启动图片
    a.processEvents();						//(c)

    MainWindow w;
    w.show();
    splash.finish(&w);						//(e)
    return a.exec();
}
