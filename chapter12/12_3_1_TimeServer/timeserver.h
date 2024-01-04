#ifndef TIMESERVER_H
#define TIMESERVER_H

#include <QTcpServer>
class Dialog; // 服务器端声明

class TimeServer : public QTcpServer
{
  public:
    explicit TimeServer( QObject *parent = nullptr );

  protected:
    void incomingConnection( qintptr socketDescriptor );

  private:
    Dialog *dlg;
};

#endif // TIMESERVER_H
