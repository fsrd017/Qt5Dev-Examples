#include "timethread.h"
#include <QDateTime>
#include <QByteArray>
#include <QDataStream>
TimeThread::TimeThread(int socketDescriptor,QObject *parent):QThread(parent),socketDescriptor(socketDescriptor)
{

}
void TimeThread::run()
{
    QTcpSocket tcpSocket;				//创建一个QTcpSocket类
    if(!tcpSocket.setSocketDescriptor(socketDescriptor))	//(a)
    {
        emit error(tcpSocket.error());						//(b)
        return;
    }
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_8);
    uint time2u = QDateTime::currentDateTime().toTime_t();	//(c)
    out<<time2u;
    tcpSocket.write(block);				//将获得的当前时间传回客户端
    tcpSocket.disconnectFromHost();		//断开连接
    tcpSocket.waitForDisconnected();	//等待返回
}
