#include "mouseevent.h"

MouseEvent::MouseEvent( QWidget *parent )
    : QMainWindow( parent )
{
    this->setWindowTitle( tr( "鼠标事件" ) );
    statusLabel = new QLabel;
    statusLabel->setText( tr( "当前位置" ) );
    statusLabel->setFixedWidth( 100 );

    MousePosLabel = new QLabel;
    MousePosLabel->setText( tr( "" ) );
    MousePosLabel->setFixedWidth( 100 );

    statusBar()->addPermanentWidget( statusLabel );
    statusBar()->addPermanentWidget( MousePosLabel );

    this->setMouseTracking( true );
    this->resize( 400, 200 );
}

MouseEvent::~MouseEvent() {}

void MouseEvent::mousePressEvent( QMouseEvent *e )
{
    QString str =
        "(" + QString::number( e->pos().x() ) + "," + QString::number( e->pos().y() ) + ")";
    if ( e->button() == Qt::LeftButton )
    {
        statusBar()->showMessage( tr( "左键" ) + str );
    }
    else if ( e->button() == Qt::RightButton )
    {
        statusBar()->showMessage( tr( "右键" ) + str );
    }
    else if ( e->button() == Qt::MiddleButton )
    {
        statusBar()->showMessage( tr( "中键" ) + str );
    }
}

void MouseEvent::mouseMoveEvent( QMouseEvent *e )
{
    MousePosLabel->setText( "(" + QString::number( e->pos().x() ) + ")," +
                            QString::number( e->pos().y() ) + ")" );
}

void MouseEvent::mouseReleaseEvent( QMouseEvent *e )
{
    QString str =
        "(" + QString::number( e->pos().x() ) + "," + QString::number( e->pos().y() ) + ")";
    statusBar()->showMessage( tr( "释放在：" ) + str, 3000 );
}

void MouseEvent::mouseDoubleClickEvent( QMouseEvent *e ) {}
