#include "networkinfomation.h"

NetworkInfomation::NetworkInfomation( QWidget *parent )
    : QWidget( parent )
{
    hostLabel             = new QLabel( tr( "主机名：" ) );
    lineEditLocalHostName = new QLineEdit;
    ipLabel               = new QLabel( tr( "IP地址：" ) );
    lineEditAddress       = new QLineEdit;
    detailBtn             = new QPushButton( tr( "详细" ) );

    mainLayout = new QGridLayout( this );
    mainLayout->addWidget( hostLabel, 0, 0 );
    mainLayout->addWidget( lineEditLocalHostName, 0, 1 );
    mainLayout->addWidget( ipLabel, 1, 0 );
    mainLayout->addWidget( lineEditAddress, 1, 1 );
    mainLayout->addWidget( detailBtn, 2, 0, 1, 2 );

    getHostInformation();
    connect( detailBtn, &QPushButton::clicked, this, &NetworkInfomation::slotDetail );
}

NetworkInfomation::~NetworkInfomation() {}

void NetworkInfomation::getHostInformation()
{
    QString localHostName = QHostInfo::localHostName();
    lineEditLocalHostName->setText( localHostName );
    QHostInfo hostInfo = QHostInfo::fromName( localHostName );

    // 获取主机的IP地址列表
    QList<QHostAddress> listAddress = hostInfo.addresses();
    if ( !listAddress.isEmpty() )
    {
        lineEditAddress->setText( listAddress.at( 2 ).toString() );
    }
}

void NetworkInfomation::slotDetail()
{
    QString                  detail = "";
    QList<QNetworkInterface> list   = QNetworkInterface::allInterfaces();

    for ( int i = 0; i < list.count(); i++ )
    {
        QNetworkInterface interface = list.at( i );
        detail                      = detail + tr( "设备：" ) + interface.name() + "\n";
        detail = detail + tr( "硬件地址： " ) + interface.hardwareAddress() + " \n";

        QList<QNetworkAddressEntry> entryList = interface.addressEntries();
        for ( int j = 1; j < entryList.count(); j++ )
        {
            QNetworkAddressEntry entry = entryList.at( j );
            detail = detail + "\t" + tr( "IP地址：" ) + entry.ip().toString() + "\n";
            detail = detail + "\t" + tr( " 子网掩码： " ) + entry.netmask().toString() + "\n";
            detail = detail + "\t" + tr( "广播地址： " ) + entry.broadcast().toString() + "\n";
        }
    }
    QMessageBox::information( this, tr( "Detail" ), detail );
}
