#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qdom.h"
#include <QDateTime>   //时间日期库
#include <QFile>       //系统文件库
#include <QFileDialog> //文件对话库
#include <QMainWindow>
#include <QMessageBox>
#include <QNetworkInterface> //网络(IP地址)接口类库
#include <QUdpSocket>        //使用UDP套接口的类库

class FileSrvDlg;
class FileCntDlg;

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

enum ChatMsgType
{
    ChatMsg,
    OnLine,
    OffLine,
    SfileName,
    RefFile
}; // 定义5种UDP消息类型

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow( QWidget *parent = nullptr );
    ~MainWindow();
    void    initMainWindow();                                         // 窗口初始化方法
    void    onLine( QString name, QString time );                     // 新用户上线
    void    offLine( QString name, QString time );                    // 用户离线
    void    sendChatMsg( ChatMsgType msgType, QString rmtName = "" ); // 发送UDP消息
    QString getLocHostIp();                                           // 获取本端的IP地址
    QString getLocChatMsg(); // 获取本端的聊天信息内容
    void    recvFileName( QString name, QString hostip, QString rmtname, QString filename );

  protected:
    void closeEvent( QCloseEvent *event ); // 重写关闭窗口方法以便发送通知离线消息

  private slots:
    void on_sendPushButton_clicked();   // 发送按钮单击事件
    void recvAndProcessChatMsg();       // 接收并处理UDP数据报
    void on_searchPushButton_clicked(); // 搜索线上用户
    void getSfileName( QString fname );
    void on_transPushButton_clicked();

  private:
    Ui::MainWindow *ui;
    QString         myname = "";
    QUdpSocket     *myUdpSocket;
    qint16          myUdpPort;
    QDomDocument    myDoc;
    QString         myFileName;
    FileSrvDlg     *myfsrv;
};
#endif // MAINWINDOW_H
