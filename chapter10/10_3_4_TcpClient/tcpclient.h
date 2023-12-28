#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QDialog>
#include <QGridLayout>
#include <QHostAddress>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QTcpSocket>

class TcpClient : public QDialog
{
    Q_OBJECT

  public:
    TcpClient( QWidget *parent = nullptr );
    ~TcpClient();

  public slots:
    void slotEnter();
    void slotConnected();
    void slotDisconnected();
    void dataReceived();
    void slotSend();

  private:
    QListWidget  *contentListWidget;
    QLineEdit    *sendLineEdit;
    QPushButton  *sendBtn;
    QLabel       *userNameLabel;
    QLineEdit    *userNameLineEdit;
    QLabel       *serverIPLabel;
    QLineEdit    *serverIPLineEdit;
    QLabel       *portLabel;
    QLineEdit    *portLineEdit;
    QPushButton  *enterBtn;
    QGridLayout  *mainLayout;
    bool          status;
    int           port;
    QHostAddress *serverIp;
    QString       userName;
    QTcpSocket   *tcpSocket;
};
#endif // TCPCLIENT_H
