#include "tcpserver.h"

TcpServer::TcpServer( QWidget *parent )
    : QDialog( parent )
{
    this->setWindowTitle( tr( "TCP Server" ) );
    contentListWidget = new QListWidget;
    portLabel         = new QLabel( tr( "端口： " ) );
    portLineEdit      = new QLineEdit;
    createBtn         = new QPushButton( tr( "创建聊天室" ) );
    mainLayout        = new QGridLayout( this );
    mainLayout->addWidget( contentListWidget, 0, 0, 1, 2 );
    mainLayout->addWidget( portLabel, 1, 0 );
    mainLayout->addWidget( portLineEdit, 1, 1 );
    mainLayout->addWidget( createBtn, 2, 0, 1, 2 );

    port = 8010;
    portLineEdit->setText( QString::number( port ) );

    connect( createBtn, &QPushButton::clicked, this, &TcpServer::slotCreateServer );
}

TcpServer::~TcpServer() {}

void TcpServer::slotCreateServer()
{
    server = new Server( this, port );
    connect( server, &Server::updateServer, this, &TcpServer::updateServer );
    createBtn->setEnabled( false );
}

void TcpServer::updateServer( QString msg, int length )
{
    contentListWidget->addItem( msg.left( length ) );
}
