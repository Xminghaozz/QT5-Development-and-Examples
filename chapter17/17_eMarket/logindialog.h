#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QCryptographicHash> //包含MD5算法库
#include <QDialog>
#include <QMessageBox>
#include <QSqlQuery> //查询MySQL的库

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

    QString strToMD5( QString str ); // 将口令字符串转换为MD5加密

  private slots:
    void on_loginPushButton_clicked(); // 登录按钮单击事件槽
    void on_exitPushButton_clicked();  // 退出按钮单击事件槽

  private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
