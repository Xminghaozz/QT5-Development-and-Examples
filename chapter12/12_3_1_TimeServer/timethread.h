#ifndef TIMETHREAD_H
#define TIMETHREAD_H

#include <QTcpSocket>
#include <QThread>
#include <QtNetwork>

class TimeThread : public QThread
{
    Q_OBJECT
  public:
    explicit TimeThread( qintptr socketDescriptor, QObject *parent = nullptr );
    void run(); // 重写此虚函数

  signals:
    void error( QTcpSocket::SocketError socketError ); // 出错信号

  private:
    qintptr socketDescriptor; // 套接字描述符
};

#endif // TIMETHREAD_H
