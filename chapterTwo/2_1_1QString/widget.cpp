#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QString str1 = "Welcome";
    str1 =str1+"to you";        //strl=" Welcome to you! "
    QString str2 = "Hello";
    str2+="World";              //str2="Hello,World! "

    str1 ="Welcome";
    str2 ="to";
    str1. append (str2);        //str1=" Welcome to"
    str1. append ("you! ");     //str1="Welcome to you! "

    str1 = QString("%1 was born in %2").arg("John").arg(1998);   // str=John was born in 1998.

    // 字符串去除空白
    str1 = " Welcome \t to \n you   ";
    str1 = str1.trimmed();      //str1 =" Welcome \t to \n _you! "
    str1 = str1.simplified();   //str1 ="Welcome to you!"

    // 查询字符串
    QString str="Welcome to you! ";
    str.startsWith("Welcorne",Qt::CaseSensitive);   //返回 true
    str.startsWith("you", Qt::CaseSensitive);       //返回 false

    str=" Welcome to you! ";
    bool ok = str.contains("Welcome", Qt::CaseSensitive); // 返回 true

    // 字符串转换
    str="125";                          //初始化一个 "125" 的字符串
    int hex=str. toInt (&ok, 16) ;      // ok=true, hex=293
    int dec=str.toInt(&ok,10);

    str=" Welcome to you! ";
    QByteArray ba =str.toLocal8Bit();
    qDebug ()<<ba;
    ba.append("Hello, World! ");
    qDebug()<<ba.data() ;
}

Widget::~Widget()
{
}

