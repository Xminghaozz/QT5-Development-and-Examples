#include "digiclock.h"
#include <QMouseEvent>
#include <QTime>
#include <QTimer>

DigiClock::DigiClock( QWidget *parent )
    : QLCDNumber( parent )
    , showColon( true )
{
    // 设置时钟背景
    QPalette p = palette();
    p.setColor( QPalette::Window, Qt::white );
    setPalette( p );

    setWindowFlags( Qt::FramelessWindowHint );
    setWindowOpacity( 0.5 );

    QTimer *timer = new QTimer( this ); // 新建一个定时器对象
    connect( timer, &QTimer::timeout, this, &DigiClock::showTime );
    timer->start( 1000 );

    showTime();        // 初始时间显示
    resize( 150, 60 ); // 设置电子时钟尺寸
}

void DigiClock::mousePressEvent( QMouseEvent *event )
{
    if ( event->button() == Qt::LeftButton )
    {
        dragPosition = event->globalPosition().toPoint() - this->frameGeometry().topLeft();
        event->accept();
    }
    if ( event->button() == Qt::RightButton )
    {
        close();
    }
}

void DigiClock::mouseMoveEvent( QMouseEvent *event )
{
    if ( event->buttons() & Qt::LeftButton )
    {
        this->move( event->globalPosition().toPoint() - dragPosition );
        event->accept();
    }
}

void DigiClock::showTime()
{
    QTime   time = QTime::currentTime();
    QString text = time.toString( "hh:mm" );
    if ( showColon )
    {
        text[ 2 ] = ':';
        showColon = false;
    }
    else
    {
        text[ 2 ] = ' ';
        showColon = true;
    }
    display( text ); // 显示转换后的字符串时间
}
