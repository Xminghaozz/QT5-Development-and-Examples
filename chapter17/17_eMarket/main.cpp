#include "logindialog.h"
#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QProcess> //Qt进程模块
#include <QSqlDatabase>
#include <QSqlQuery>

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    // QSqlDatabase sqldb = QSqlDatabase::addDatabase( "QMYSQL" );
    // sqldb.setDatabaseName( "emarket" );
    // sqldb.setHostName( "localhost" );
    // sqldb.setPort( 3306 );
    // sqldb.setUserName( "root" );
    // sqldb.setPassword( "001127" );

    // if ( !sqldb.open() )
    // {
    //     QMessageBox::critical( 0, QObject::tr( "后台数据库连接失败！" ), "无法创建连接",
    //                            QMessageBox::Cancel );
    //     return -1;
    // }

    // // 向数据库中插入图片
    // QSqlQuery query( sqldb );
    // QString   photoPath = ":/Img/logo.jpg"; // 照片容量不能大于60KB
    // QFile     photoFile( photoPath );
    // if ( photoFile.exists() )
    // {
    //     // 存入数据库
    //     QByteArray picdata;
    //     photoFile.open( QIODevice::ReadOnly );
    //     picdata = photoFile.readAll();
    //     photoFile.close();
    //     QVariant var( picdata );
    //     QString  sqlstr = "update commodity set Picture=? Where CommodityID=1";
    //     query.prepare( sqlstr );
    //     query.addBindValue( var );

    //     if ( !query.exec() )
    //     {
    //         QMessageBox::information( 0, QObject::tr( "提示" ), "图片写入失败" );
    //     }
    //     else
    //     {
    //         QMessageBox::information( 0, QObject::tr( "提示" ), "图片已写入数据库" );
    //     }
    // }

    // sqldb.close();
    if ( !createMySqlConn() )
    {
        // 若初次尝试连接不成功，就用代码方式启动MySQL服务进程
        QProcess process;
        process.start( "C:/Program Files/MySQL/MySQL Server 8.0/bin/mysql.exe" );
        // 第二次尝试连接
        if ( !createMySqlConn() )
        {
            return 1;
        }
    }

    LoginDialog loginDlg; // 登录对话框类
    if ( loginDlg.exec() == QDialog::Accepted )
    {
        MainWindow w;
        w.show();
        return a.exec();
    }
    else
    {
        return 0;
    }
}
