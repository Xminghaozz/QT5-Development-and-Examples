#ifndef TIMECLIENT_H
#define TIMECLIENT_H

#include <QAbstractSocket>
#include <QDateTimeEdit>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTcpSocket>

class TimeClient : public QDialog
{
    Q_OBJECT

  public:
    TimeClient( QWidget *parent = nullptr );
    ~TimeClient();
  public slots:
    void enableGetBtn();
    void getTime();
    void readTime();
    void showError( QAbstractSocket::SocketError socketError );

  private:
    QLabel        *serverNameLabel;
    QLineEdit     *serverNameLineEdit;
    QLabel        *portLabel;
    QLineEdit     *portLineEdit;
    QDateTimeEdit *dateTimeEdit;
    QLabel        *stateLabel;
    QPushButton   *getBtn;
    QPushButton   *quitBtn;
    uint           time2u;
    QTcpSocket    *tcpSocket;
};
#endif // TIMECLIENT_H
