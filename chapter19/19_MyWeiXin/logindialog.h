#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include "mainwindow.h"
#include "qdom.h" //用于操作XML中的DOM对象的库
#include <QDialog>
#include <QFile>

namespace Ui
{
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

  public:
    explicit LoginDialog( QWidget *parent = nullptr );
    ~LoginDialog();

  private slots:
    void on_loginPushButton_clicked(); // 登录按钮的单击事件方法
    void showWeiChatWindow();          // 根据验证的结果决定是否显示聊天窗口

  private:
    Ui::LoginDialog *ui;
    MainWindow      *weiChatWindow; // 指向聊天窗口的指针
    QDomDocument     mydoc;         // 全局变量用于获取XML中的DOM对象
};

#endif // LOGINDIALOG_H
