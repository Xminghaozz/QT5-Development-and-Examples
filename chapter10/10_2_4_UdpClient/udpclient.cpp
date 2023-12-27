#include "udpclient.h"
#include <QHostAddress>
#include <QMessageBox>

UdpClient::UdpClient( QWidget *parent )
    : QDialog( parent )
{
    this->setWindowTitle( tr( "UDP Client" ) );
    /*初始化各个控件*/
    receiveTextEdit = new QTextEdit( this );
    closeBtn        = new QPushButton( tr( "Close" ), this );
    /*设置布局*/
    mainLayout = new QVBoxLayout( this );
    mainLayout->addWidget( receiveTextEdit );
    mainLayout->addWidget( closeBtn );

    connect( closeBtn, &QPushButton::clicked, this, &UdpClient::closeBtnClicked );
    port      = 5555; // 设置UDP的端口号参数，指定在此端口上监听数据
    udpSocket = new QUdpSocket( this ); // 创建一个QUdpSocket
    connect( udpSocket, &QUdpSocket::readyRead, this, &UdpClient::dataReceived );

    bool result = udpSocket->bind( port ); // 绑定到指定端口
    if ( !result )
    {
        QMessageBox::information( this, tr( "error" ), tr( "udp socket create error!" ) );
        return;
    }
}

UdpClient::~UdpClient() {}

void UdpClient::closeBtnClicked() { close(); }

void UdpClient::dataReceived()
{
    while ( udpSocket->hasPendingDatagrams() )
    {
        QByteArray datagram;
        datagram.resize( udpSocket->pendingDatagramSize() );
        udpSocket->readDatagram( datagram.data(), datagram.size() );
        QString msg = datagram.data();
        receiveTextEdit->insertPlainText( msg ); // 显示数据内容
    }
}
