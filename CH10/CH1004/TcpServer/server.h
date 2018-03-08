#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QObject>
#include "tcpclientsocket.h"    //包含TCP的套接字
class Server : public QTcpServer
{
    Q_OBJECT                    //添加宏(Q_OBJECT)是为了实现信号与槽的通信
public:
    Server(QObject *parent=0,int port=0);
    QList<TcpClientSocket*> tcpClientSocketList;
signals:
    void updateServer(QString,int);
public slots:
    void updateClients(QString,int);
    void slotDisconnected(int);
protected:
    void incomingConnection(int socketDescriptor);
};

#endif // SERVER_H
