#include "mainwindow.h"

#include "logindialog.h"
#include <QApplication>
#include <QCoreApplication>
#include <QNetworkInterface>

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    LoginDialog  logindlg;
    logindlg.show();

    // 获取当前主机的所有网络地址
    QList<QHostAddress> addressList = QNetworkInterface::allAddresses();

    // 遍历所有地址并输出
    foreach ( const QHostAddress &address, addressList )
    {
        if ( address != QHostAddress::LocalHost && address != QHostAddress::LocalHostIPv6 )
        {
            if ( address.protocol() == QAbstractSocket::IPv4Protocol )
            {
                qDebug() << "IPv4 Address:" << address.toString();
            }
            else if ( address.protocol() == QAbstractSocket::IPv6Protocol )
            {
                qDebug() << "IPv6 Address:" << address.toString();
            }
            else
            {
                qDebug() << "Other Address:" << address.toString();
            }
        }
    }
    // MainWindow w;
    // w.show();
    return a.exec();
}
