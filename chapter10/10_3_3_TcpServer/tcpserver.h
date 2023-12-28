#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "server.h"
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>

class TcpServer : public QDialog
{
    Q_OBJECT

  public:
    TcpServer( QWidget *parent = nullptr );
    ~TcpServer();

  public slots:
    void slotCreateServer();
    void updateServer( QString, int );

  private:
    QListWidget *contentListWidget;
    QLabel      *portLabel;
    QLineEdit   *portLineEdit;
    QPushButton *createBtn;
    QGridLayout *mainLayout;
    int          port;
    Server      *server;
};
#endif // TCPSERVER_H
