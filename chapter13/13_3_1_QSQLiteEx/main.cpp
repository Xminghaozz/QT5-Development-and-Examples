#include <QByteArray>
#include <QCoreApplication>
#include <QDebug>
#include <QElapsedTimer>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>

int main( int argc, char *argv[] )
{
    QCoreApplication a( argc, argv );
    QSqlDatabase     db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setHostName( "easybook-3313b0" ); // 设置数据库主机名
    db.setDatabaseName( "qtDB.db" );
    db.setUserName( "xmh" );
    db.setPassword( "001127" );

    if ( !db.open() ) // 打开连接
    {
        qDebug() << "Failed to open database";
        return 1;
    }

    // 创建数据库表
    QSqlQuery query;
    bool      success = query.exec(
        "create table automobil(id int primary key,attribute varchar,type varchar,kind "
             "varchar,nation int,carnumber int,elevaltor int,distance int,oil int,temperature int)" );

    if ( success )
        qDebug() << QObject::tr( "数据库表创建成功！\n" );
    else
        qDebug() << QObject::tr( "数据库表创建失败！\n" );

    // 查询
    query.exec( "select * from automobil" );
    QSqlRecord rec = query.record();
    qDebug() << QObject::tr( "automobil 表字段数： " ) << rec.count();

    // 插入记录
    QElapsedTimer t;
    t.start(); // 启动一个计时器，统计操作耗时
    query.prepare( "insert into automobil values(?,?,?,?,?,?,?,?,?,?)" );
    long records = 100; // 向表中插入任意100条记录
    for ( int i = 0; i < records; i++ )
    {
        query.addBindValue( i );
        query.addBindValue( "四轮" );
        query.addBindValue( "轿车" );
        query.addBindValue( "富康" );
        query.addBindValue( rand() % 100 );
        query.addBindValue( rand() % 10000 );
        query.addBindValue( rand() % 300 );
        query.addBindValue( rand() % 200000 );
        query.addBindValue( rand() % 52 );
        query.addBindValue( rand() % 100 );

        success = query.exec();
        if ( !success )
        {
            QSqlError lastError = query.lastError();
            qDebug() << lastError.driverText() << QString( QObject::tr( "插入失败！" ) );
        }
        query.finish(); // 完成一次插入，清空绑定值
    }
    qDebug() << QObject::tr( "插入 %1 条记录，耗时：%2ms" ).arg( records ).arg( t.elapsed() );

    // 排序
    t.restart(); // 重启计时器
    success = query.exec( "select * from automobil order by id desc" );
    if ( success )
    {
        qDebug() << QObject::tr( "排序%1条记录,耗时：%2ms" )
                        .arg( records )
                        .arg( t.elapsed() ); // 输出操作耗时
    }
    else
    {
        qDebug() << QObject::tr( "排序失败！" );
    }

    // 更新记录
    t.restart(); // 重启计时器
    for ( int i = 0; i < records; i++ )
    {
        query.prepare( QString( "update automobil set attribute=?,type=?,"
                                "kind=?,nation=?,"
                                "carnumber=?,elevaltor=?,"
                                "distance=?,oil=?,"
                                "temperature=? where id=%1" )
                           .arg( i ) );

        query.addBindValue( "四轮" );
        query.addBindValue( "轿车" );
        query.addBindValue( "富康" );
        query.addBindValue( rand() % 100 );
        query.addBindValue( rand() % 10000 );
        query.addBindValue( rand() % 300 );
        query.addBindValue( rand() % 200000 );
        query.addBindValue( rand() % 52 );
        query.addBindValue( rand() % 100 );

        success = query.exec();
        if ( !success )
        {
            QSqlError lastError = query.lastError();
            qDebug() << lastError.driverText() << QString( QObject::tr( "更新失败" ) );
        }
    }
    qDebug() << QObject::tr( "更新 %1 条记录，耗时：%2 ms" ).arg( records ).arg( t.elapsed() );

    // 删除
    t.restart();
    query.exec( "delete from automobil where id=15" );
    qDebug() << QObject::tr( "删除一条记录，耗时：%1 ms" ).arg( t.elapsed() );

    db.close();
    return 0;
}
