#include "udpserver.h"
#include <QHostAddress>

UdpServer::UdpServer( QWidget *parent )
    : QDialog( parent )
{
    this->setWindowTitle( tr( "UDP Server" ) );
    /*初始化各个控件*/
    timerLabel   = new QLabel( tr( "计时器" ) );
    textLineEdit = new QLineEdit( this );
    startBtn     = new QPushButton( tr( "开始" ), this );
    /*设置布局*/
    mainLayout = new QVBoxLayout( this );
    mainLayout->addWidget( timerLabel );
    mainLayout->addWidget( textLineEdit );
    mainLayout->addWidget( startBtn );

    connect( startBtn, &QPushButton::clicked, this, &UdpServer::startBtnClicked );
    port = 5555; // 设置UDP的端口号参数，服务器定时向此端口发送广播消息
    isStarted = false;
    udpSocket = new QUdpSocket( this ); // 创建一个QUdoSocket
    timer     = new QTimer( this );

    // 定发送广播消息
    connect( timer, &QTimer::timeout, this, &UdpServer::timeout );
}

UdpServer::~UdpServer() {}

void UdpServer::startBtnClicked()
{
    if ( !isStarted )
    {
        startBtn->setText( tr( "停止" ) );
        timer->start( 1000 );
        isStarted = true;
    }
    else
    {
        startBtn->setText( tr( "开始" ) );
        isStarted = false;
        timer->stop();
    }
}

void UdpServer::timeout()
{
    QString msg    = textLineEdit->text();
    int     length = 0;
    if ( msg == "" )
    {
        return;
    }
    if ( ( length = udpSocket->writeDatagram( msg.toLatin1(), msg.length(), QHostAddress::Broadcast,
                                              port ) ) != msg.length() )    //QHostAddress: :Broadcast 指定向广播地址发送。
    {
        return;
    }
}
