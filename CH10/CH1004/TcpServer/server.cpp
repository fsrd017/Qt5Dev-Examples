#include "server.h"

Server::Server(QObject *parent,int port):QTcpServer(parent)
{
    listen(QHostAddress::Any,port);
}
void Server::incomingConnection(int socketDescriptor)
{
    TcpClientSocket *tcpClientSocket=new TcpClientSocket(this);
                                                            //(a)
    connect(tcpClientSocket,SIGNAL(updateClients(QString,int)),
            this,SLOT(updateClients(QString,int)));			//(b)
    connect(tcpClientSocket,SIGNAL(disconnected(int)),this,
            SLOT(slotDisconnected(int)));					//(c)
    tcpClientSocket->setSocketDescriptor(socketDescriptor);
                                                            //(d)
    tcpClientSocketList.append(tcpClientSocket);			//(e)
}
void Server::updateClients(QString msg,int length)
{
    emit updateServer(msg,length);                          //(a)
    for(int i=0;i<tcpClientSocketList.count();i++)          //(b)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->write(msg.toLatin1(),length)!=length)
        {
            continue;
        }
    }
}
void Server::slotDisconnected(int descriptor)
{
    for(int i=0;i<tcpClientSocketList.count();i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->socketDescriptor()==descriptor)
        {
            tcpClientSocketList.removeAt(i);
            return;
        }
    }
    return;
}
