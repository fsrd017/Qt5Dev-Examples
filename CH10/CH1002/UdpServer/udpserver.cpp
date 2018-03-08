#include "udpserver.h"
#include <QHostAddress>
UdpServer::UdpServer(QWidget *parent,Qt::WindowFlags f)
    : QDialog(parent,f)
{
    setWindowTitle(tr("UDP Server"));			//设置窗体的标题
    /* 初始化各个控件 */
    TimerLabel = new QLabel(tr("计时器："),this);
    TextLineEdit = new QLineEdit(this);
    StartBtn = new QPushButton(tr("开始"),this);
    /* 设置布局 */
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(TimerLabel);
    mainLayout->addWidget(TextLineEdit);
    mainLayout->addWidget(StartBtn);
    connect(StartBtn,SIGNAL(clicked()),this,SLOT(StartBtnClicked()));
    port = 5555;		//设置UDP的端口号参数，服务器定时向此端口发送广播信息
    isStarted = false;
    udpSocket = new QUdpSocket(this);
    timer = new QTimer(this);		//创建一个QUdpSocket
    //定时发送广播信息
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));
}

void UdpServer::StartBtnClicked()
{
    if(!isStarted)
    {
        StartBtn->setText(tr("停止"));
        timer->start(1000);
        isStarted =true;
    }
    else
    {
        StartBtn->setText(tr("开始"));
        isStarted = false;
        timer->stop();
    }
}

void UdpServer::timeout()
{
    QString msg = TextLineEdit->text();
    int length=0;
    if(msg=="")
    {
       return;
    }
    if((length=udpSocket->writeDatagram(msg.toLatin1(),
    msg.length(),QHostAddress::Broadcast,port))!=msg.length())
    {
        return;
    }
}

UdpServer::~UdpServer()
{

}
