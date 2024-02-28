#ifndef FILECNTDLG_H
#define FILECNTDLG_H

#include <QDialog>
#include <QElapsedTimer>
#include <QFile>
#include <QHostAddress> //网络IP地址类库
#include <QTcpSocket>   //Tcp套接口类库

class QTcpSocket;

namespace Ui
{
class FileCntDlg;
}

class FileCntDlg : public QDialog
{
    Q_OBJECT

  public:
    explicit FileCntDlg( QWidget *parent = nullptr );
    ~FileCntDlg();
    void getSrvAddr( QHostAddress saddr ); // 获取服务端IP
    void getLocPath( QString lpath );      // 获取本地文件保存路径

  protected:
    void closeEvent( QCloseEvent * );

  private slots:
    void createConnToSrv();               // 连接到服务器
    void readChatMsg();                   // 读取服务器发来的文件数据
    void on_cntClosePushButton_clicked(); //"停止"按钮的单击事件过程

  private:
    Ui::FileCntDlg *ui;
    QTcpSocket     *myCntSocket;
    QHostAddress    mySrvAddr;
    qint16          mySrvPort;
    qint64          myTotalBytes;
    qint64          myRcvedBytes;
    QByteArray      myInputBlock;
    quint16         myBlockSize;
    QFile          *myLocPathFile;
    QString         myFileName;
    qint64          myFileNameSize;
    QElapsedTimer   mytime;
};

#endif // FILECNTDLG_H
