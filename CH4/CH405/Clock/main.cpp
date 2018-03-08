#include "dialog.h"
#include <QApplication>
#include "digiclock.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DigiClock clock;
    clock.show();

    //Dialog w;
    //w.show();

    return a.exec();
}
