#include "mainwindow.h"
#include <QDataStream>
#include <QDate>
#include <QFile>
#include <QtDebug>

MainWindow::MainWindow( QWidget *parent )
    : QMainWindow( parent )
{
    fileFun();
}

MainWindow::~MainWindow() {}

void MainWindow::fileFun()
{
    /*将二进制数据写到数据流*/
    QFile file( "binary.dat" );
    file.open( QIODevice::WriteOnly | QIODevice::Truncate );
    QDataStream out( &file );           // 将数据序列化
    out << QString( tr( "薛明昊：" ) ); // 字符串序列化
    out << QDate::fromString( "2000/11/27", "yyyy/MM/dd" );
    out << (qint32) 23; // 整数序列化
    file.close();

    /*从文件中读取数据*/
    file.setFileName( "binary.dat" );
    if ( !file.open( QIODevice::ReadOnly ) )
    {
        qDebug() << "error!";
        return;
    }

    QDataStream in( &file ); // 从文件中读出数据
    QString     name;
    QDate       birthday;
    qint32      age;
    in >> name >> birthday >> age; // 获取字符串和整数
    qDebug() << name << birthday << age;
    file.close();
}
