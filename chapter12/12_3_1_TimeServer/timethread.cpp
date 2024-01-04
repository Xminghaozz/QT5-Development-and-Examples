#include "timethread.h"
#include <QByteArray>
#include <QDataStream>
#include <QDateTime>

TimeThread::TimeThread( qintptr socketDescriptor, QObject *parent )
    : QThread( parent )
    , socketDescriptor( socketDescriptor )
{
}

void TimeThread::run()
{
    QTcpSocket tcpSocket; // 创建一个QTcpSocket类
    if ( !tcpSocket.setSocketDescriptor( socketDescriptor ) )
    {
        emit error( tcpSocket.error() );
        return;
    }

    QByteArray  block;
    QDataStream out( &block, QIODevice::WriteOnly );
    out.setVersion( QDataStream::Qt_6_0 );
    uint time2u = QDateTime::currentDateTime().toSecsSinceEpoch();
    out << time2u;

    tcpSocket.write( block );        // 将获得的当前时间传回客户端
    tcpSocket.disconnectFromHost();  // 断开连接
    tcpSocket.waitForDisconnected(); // 等待返回
}
