#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>

class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT; // 添加宏(Q_OBJECT) 是为了实现信号与槽的通信
  public:
    explicit TcpClientSocket( QObject *parent = nullptr );

  signals:
    void updateClients( QString, int );
    void disconnected( int );

  protected slots:
    void dataReceived();
    void slotDisconnected();
};

#endif // TCPCLIENTSOCKET_H
