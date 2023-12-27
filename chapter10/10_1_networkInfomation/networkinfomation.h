#ifndef NETWORKINFOMATION_H
#define NETWORKINFOMATION_H

#include <QGridLayout>
#include <QHostInfo>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QNetworkinterface>
#include <QPushButton>
#include <QWidget>

class NetworkInfomation : public QWidget
{
    Q_OBJECT

  public:
    NetworkInfomation( QWidget *parent = nullptr );
    ~NetworkInfomation();
    void getHostInformation();

  public slots:
    void slotDetail();

  private:
    QLabel      *hostLabel;
    QLineEdit   *lineEditLocalHostName;
    QLabel      *ipLabel;
    QLineEdit   *lineEditAddress;
    QPushButton *detailBtn;
    QGridLayout *mainLayout;
};
#endif // NETWORKINFOMATION_H
