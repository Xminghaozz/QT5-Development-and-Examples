#include "tcpclient.h"
#include <QHostInfo>
#include <QMessageBox>

TcpClient::TcpClient( QWidget *parent )
    : QDialog( parent )
{
    setWindowTitle( tr( "TCP Client" ) );

    contentListWidget = new QListWidget;
    sendLineEdit      = new QLineEdit;
    sendBtn           = new QPushButton( tr( " 发送" ) );
    userNameLabel     = new QLabel( tr( " 用户: " ) );
    userNameLineEdit  = new QLineEdit;
    serverIPLabel     = new QLabel( tr( " 服务器地址：" ) );
    serverIPLineEdit  = new QLineEdit;
    portLabel         = new QLabel( tr( " 端口：" ) );
    portLineEdit      = new QLineEdit;
    enterBtn          = new QPushButton( tr( " 进入聊天室" ) );

    mainLayout = new QGridLayout( this );
    mainLayout->addWidget( contentListWidget, 0, 0, 1, 2 );
    mainLayout->addWidget( sendLineEdit, 1, 0 );
    mainLayout->addWidget( sendBtn, 1, 1 );
    mainLayout->addWidget( userNameLabel, 2, 0 );
    mainLayout->addWidget( userNameLineEdit, 2, 1 );
    mainLayout->addWidget( serverIPLabel, 3, 0 );
    mainLayout->addWidget( serverIPLineEdit, 3, 1 );
    mainLayout->addWidget( portLabel, 4, 0 );
    mainLayout->addWidget( portLineEdit, 4, 1 );
    mainLayout->addWidget( enterBtn, 5, 0, 1, 2 );

    status = false;
    port   = 8010;
    portLineEdit->setText( QString::number( port ) );
    serverIp = new QHostAddress();

    connect( enterBtn, &QPushButton::clicked, this, &TcpClient::slotEnter );
    connect( sendBtn, &QPushButton::clicked, this, &TcpClient::slotSend );
    sendBtn->setEnabled( false );
}

TcpClient::~TcpClient() {}

void TcpClient::slotEnter()
{
    if ( !status )
    {
        /*完成合法性输入校验*/
        QString ip = serverIPLineEdit->text();
        if ( !serverIp->setAddress( ip ) )
        {
            QMessageBox::information( this, tr( "error" ), tr( "server ip address error!" ) );
            return;
        }

        if ( userNameLineEdit->text() == "" )
        {
            QMessageBox::information( this, tr( "error" ), tr( "User name error!" ) );
            return;
        }

        userName = userNameLineEdit->text();

        /*创建一个QTcpSocket类对象，并将信号/槽连接起来*/
        tcpSocket = new QTcpSocket( this );
        connect( tcpSocket, &QTcpSocket::connected, this, &TcpClient::slotConnected );
        connect( tcpSocket, &QTcpSocket::disconnected, this, &TcpClient::slotDisconnected );
        connect( tcpSocket, &QTcpSocket::readyRead, this, &TcpClient::dataReceived );
        tcpSocket->connectToHost( *serverIp, port );
        status = true;
    }
    else
    {
        int     length = 0;
        QString msg    = userName + tr( " :Leave Chat Room" );
        if ( ( length = tcpSocket->write( msg.toLatin1(), msg.length() ) ) != msg.length() )
        {
            return;
        }

        tcpSocket->disconnectFromHost();
        status = false; // 将status状态复位
    }
}

void TcpClient::slotConnected()
{
    sendBtn->setEnabled( true );
    enterBtn->setText( tr( "离开" ) );
    int     length = 0;
    QString msg    = userName + tr( ":Enter Chat Room" );
    if ( ( length = tcpSocket->write( msg.toLatin1(), msg.length() ) ) != msg.length() )
    {
        return;
    }
}

void TcpClient::slotDisconnected()
{
    sendBtn->setEnabled( false );
    enterBtn->setText( tr( " 进入聊天室 " ) );
}

void TcpClient::dataReceived()
{
    while ( tcpSocket->bytesAvailable() > 0 )
    {
        QByteArray datagram;
        datagram.resize( tcpSocket->bytesAvailable() );
        tcpSocket->read( datagram.data(), datagram.size() );
        QString msg = datagram.data();
        contentListWidget->addItem( msg.left( datagram.size() ) );
    }
}

void TcpClient::slotSend()
{
    if ( sendLineEdit->text() == "" )
    {
        return;
    }
    QString msg = userName + ":" + sendLineEdit->text();
    tcpSocket->write( msg.toLatin1(), msg.length() );
    sendLineEdit->clear();
}
