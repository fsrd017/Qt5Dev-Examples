#include "udpclient.h"
#include <QMessageBox>
#include <QHostAddress>
UdpClient::UdpClient(QWidget *parent,Qt::WindowFlags f)
    : QDialog(parent,f)
{
    setWindowTitle(tr("UDP Client"));		//设置窗体的标题
    /* 初始化各个控件 */
    ReceiveTextEdit = new QTextEdit(this);
    CloseBtn = new QPushButton(tr("Close"),this);
    /* 设置布局 */
    mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(ReceiveTextEdit);
    mainLayout->addWidget(CloseBtn);
    connect(CloseBtn,SIGNAL(clicked()),this,SLOT(CloseBtnClicked()));
    port =5555;                             //设置UDP的端口号参数，指定在此端口上监听数据
    udpSocket = new QUdpSocket(this);		//创建一个QUdpSocket
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));
                                            //(a)
    bool result=udpSocket->bind(port);		//绑定到指定的端口上
    if(!result)
    {
        QMessageBox::information(this,tr("error"),tr("udp socket create error!"));
        return;
    }
}

void UdpClient::CloseBtnClicked()
{
    close();
}

void UdpClient::dataReceived()
{
    while(udpSocket->hasPendingDatagrams())				//(a)
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());
                                                        //(b)
        QString msg=datagram.data();
        ReceiveTextEdit->insertPlainText(msg);			//显示数据内容
    }
}

UdpClient::~UdpClient()
{

}
