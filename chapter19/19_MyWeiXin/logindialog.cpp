#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog( QWidget *parent )
    : QDialog( parent )
    , ui( new Ui::LoginDialog )
{
    ui->setupUi( this );
    ui->pwdLineEdit->setFocus(); // 输入焦点初始于密码框
}

LoginDialog::~LoginDialog() { delete ui; }

void LoginDialog::on_loginPushButton_clicked()
{
    showWeiChatWindow(); // 调用显示聊天窗口方法
}

/*-------------实现登录验证-------------*/
void LoginDialog::showWeiChatWindow()
{
    QFile file( ":/userlog.xml" ); // 创建XML文件对象
    if ( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        QMessageBox::warning( 0, QObject::tr( "提示" ), "无法打开用户日志文件！" );
        return;
    }

    mydoc.setContent( &file ); // 将XML对象赋给QDomDocument类型的Qt文档句柄
    QDomElement root = mydoc.documentElement(); // 获取XML文档的DOM根元素

    if ( root.hasChildNodes() )
    {
        QDomNodeList userList = root.childNodes(); // 获取根元素的全部子节点
        bool         exist    = false;             // 指示用户是否存在

        for ( int i = 0; i < userList.count(); i++ )
        {
            QDomNode     user   = userList.at( i );
            QDomNodeList record = user.childNodes(); // 获取该用户的全部属性元素

            // 解析出用户名和密码
            QString uname = record.at( 0 ).toElement().text();
            QString pword = record.at( 1 ).toElement().text();

            if ( uname.compare( ui->userLineEdit->text(), Qt::CaseInsensitive ) == 0 )
            {
                exist = true; // 用户存在
                if ( !( pword == ui->pwdLineEdit->text() ) )
                {
                    QMessageBox::warning( 0, QObject::tr( "提示" ), "密码错误，请重新输入" );
                    ui->pwdLineEdit->clear();
                    ui->pwdLineEdit->setFocus();
                    return;
                }
            }
        }

        if ( !exist )
        {
            QMessageBox::warning( 0, QObject::tr( "提示" ), "此用户不存在！请重新输入用户名" );
            ui->userLineEdit->clear();
            ui->pwdLineEdit->clear();
            ui->userLineEdit->setFocus();
            return;
        }

        // 用户登录成功
        weiChatWindow = new MainWindow( nullptr );
        weiChatWindow->setWindowTitle( ui->userLineEdit->text() );
        weiChatWindow->show();
    }
    else
    {
        QMessageBox::warning( 0, QObject::tr( "提示" ), "用户日志文件为空！" );
    }

    file.close(); // 关闭文件
}
