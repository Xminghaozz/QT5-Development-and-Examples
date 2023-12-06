#include<QCoreApplication>
#include<QDebug>

int main(int argc, char*argv[])
{
    QCoreApplication a(argc,argv);
    QMap<QString,QString> map;              //创建一个map对象
    //向栈对象插入<城市，区号>对
    map.insert("beijing","111");
    map.insert("shanghai","021");
    map.insert("nanjing","025");

//    // Java风格迭代器
//    QMapIterator<QString,QString> i(map);   //创建一个只读迭代器
//    for(;i.hasNext();)
//    {
//        i.next();
//        qDebug()<<" "<<i.key()<<" "<<i.value();
//    }

//   QMutableMapIterator<QString,QString> mi(map);
//    if(mi.findNext("111"))
//        mi.setValue("010");
    //STL风格迭代器
    QMap<QString,QString>::const_iterator i;
    for(i = map.constBegin(); i != map.constEnd(); i++)
        qDebug()<<" "<<i.key()<<" "<<i.value();
    QMap<QString,QString>::iterator mi;
    mi=map.find("beijing");
    if(mi!=map.end())
    {
        mi.value()="010";
    }

    QMap<QString,QString>::const_iterator modi;
    qDebug () <<" ";
    for (modi = map. constBegin ();modi != map. constEnd(); ++modi)
        qDebug()<<" "<<modi.key()<<" "<<modi.value();
    return a.exec();
}
