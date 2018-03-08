#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile data("data.txt");
    if(data.open(QFile::WriteOnly|QFile::Truncate))		//(a)
    {
        QTextStream out(&data);
        out<<QObject::tr("score:")<<qSetFieldWidth(10)<<left<<90<< endl;	//(b)
    }
    return a.exec();
}
