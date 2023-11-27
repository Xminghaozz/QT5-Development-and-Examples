#include <QDebug>
#include <QCoreApplication>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    QList<QString> list;
//    {
//        QString str("This is a test string");
//        list<<str;
//    }
//    qDebug()<<list[0]<<"How are you!";

//    QList<int> list2;
//    list2<<1<<2<<3<<4<<5;       //用操作运算符"<<"输入五个整数
//    QListIterator<int> i(list2);
//    for(;i.hasNext();)
//        qDebug()<<i.next();

//    QList<int> list;
//    QMutableListIterator<int> i(list);      //创建上述列表的读写迭代器 Java风格
//    for(int j=0;j<10;j++)
//    {
//        i.insert(j);
//    }

//    for(i.toFront();i.hasNext();)           //遍历并输出列表
//        qDebug()<<i.next();

//    for(i.toBack();i.hasPrevious();)
//    {
//        if(i.previous()%2==0)
//            i.remove();
//        else
//            i.setValue(i.peekNext()*10);
//    }

//    for(i.toFront();i.hasNext();)           //重新遍历并输出列表
//        qDebug()<<i.next();

//    //STL风格的迭代器
//    QList<int> list;
//    for(int j=0;j<10;j++)
//    {
//        list.insert(list.end(),j);
//    }
//    //初始化一个 QList<int>::iterator 读写迭代器
//    QList<int>::iterator i;
//    for(i=list.begin();i!=list.end();i++)
//    {
//        qDebug()<<(*i);
//        *i = (*i)*10;
//    }
//    //初始化一个 读迭代器
//    QList<int>::const_iterator ci;
//    for(ci=list.begin();ci!=list.end();ci++)
//    {
//        qDebug()<<*ci;
//    }



    return a.exec();
}
