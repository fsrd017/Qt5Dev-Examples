#include "dialog.h"
#include <QApplication>
#include "drawer.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Drawer drawer;
    drawer.show();
    //Dialog w;
    //w.show();

    return a.exec();
}
