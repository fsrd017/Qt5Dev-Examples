#include <QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> list;						//初始化一个空的QList<int>列表
    for(int j=0;j<10;j++)
        list.insert(list.end(),j);			//(a)
    QList<int>::iterator i;
    //初始化一个QList<int>::iterator读写迭代器
    for(i=list.begin();i!=list.end();++i)	//(b)
    {
           qDebug()<<(*i);
           *i=(*i)*10;
    }
    //初始化一个QList<int>:: const_iterator读写迭代器
    QList<int>::const_iterator ci;
    //在控制台输出列表的所有值
    for(ci=list.constBegin();ci!=list.constEnd();++ci)
            qDebug()<<*ci;

    return a.exec();
}
