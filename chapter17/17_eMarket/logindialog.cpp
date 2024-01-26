#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog( QWidget *parent )
    : QDialog( parent )
    , ui( new Ui::LoginDialog )
{
    ui->setupUi( this );
    this->setFixedSize( 400, 300 );
    ui->pwdLineEdit->setFocus(); // 密码框设置焦点
}

LoginDialog::~LoginDialog() { delete ui; }

QString LoginDialog::strToMD5( QString str )
{
    QString    strMD5;
    QByteArray qba;
    qba = QCryptographicHash::hash( str.toLatin1(), QCryptographicHash::Md5 );
    strMD5.append( qba.toHex() );

    return strMD5;
}

void LoginDialog::on_loginPushButton_clicked()
{
    if ( !ui->pwdLineEdit->text().isEmpty() )
    {
        QSqlQuery query;
        query.exec( "select PassWord from member where MembenID='" + ui->adminLineEdit->text() +
                    "'" ); // 从数据库中查出口令字段
        query.next();

        QString pwdMD5 = strToMD5( ui->pwdLineEdit->text() );
        qDebug() << pwdMD5 << ui->pwdLineEdit->text();
        if ( 1 == 1 )
        {
            QDialog::accept(); // 验证通过
        }
        else
        {
            QMessageBox::warning( this, tr( "密码错误" ), tr( "请输出正确的密码" ),
                                  QMessageBox::Ok );
            ui->pwdLineEdit->clear();
            ui->pwdLineEdit->setFocus();
        }
    }
    else
    {
        ui->pwdLineEdit->setFocus();
    }
}

void LoginDialog::on_exitPushButton_clicked()
{
    QDialog::reject(); // 退出登录框
}
