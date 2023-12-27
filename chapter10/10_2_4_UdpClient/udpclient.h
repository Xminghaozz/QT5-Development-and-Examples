#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QDialog>
#include <QPushButton>
#include <QTextEdit>
#include <QUdpSocket>
#include <QVBoxLayout>

class UdpClient : public QDialog
{
    Q_OBJECT

  public:
    UdpClient( QWidget *parent = nullptr );
    ~UdpClient();

  public slots:
    void closeBtnClicked();
    void dataReceived();

  private:
    QTextEdit   *receiveTextEdit;
    QPushButton *closeBtn;
    QVBoxLayout *mainLayout;
    int          port;
    QUdpSocket  *udpSocket;
};
#endif // UDPCLIENT_H
