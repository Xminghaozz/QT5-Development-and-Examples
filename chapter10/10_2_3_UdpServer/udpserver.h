#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTimer>
#include <QUdpSocket>
#include <QVBoxLayout>

class UdpServer : public QDialog
{
    Q_OBJECT

  public:
    UdpServer( QWidget *parent = nullptr );
    ~UdpServer();

    public slots:
        void startBtnClicked();
        void timeout();

  private:
    QLabel      *timerLabel;
    QLineEdit   *textLineEdit;
    QPushButton *startBtn;
    QVBoxLayout *mainLayout;
    int port;
    bool isStarted;
    QUdpSocket *udpSocket;
    QTimer *timer;
};
#endif // UDPSERVER_H
