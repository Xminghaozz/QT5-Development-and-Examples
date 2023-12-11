#include "shapewidget.h"
#include <QBitmap>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>

ShapeWidget::ShapeWidget( QWidget *parent )
    : QWidget( parent )
{
    QPixmap pix;
    pix.load( ":/Img/16.png", 0, Qt::AvoidDither | Qt::ThresholdDither | Qt::ThresholdAlphaDither );
    this->resize( pix.size() );
    this->setMask( QBitmap( pix.mask() ) );
}

ShapeWidget::~ShapeWidget() {}

void ShapeWidget::mousePressEvent( QMouseEvent *event )
{
    if ( event->button() == Qt::LeftButton )
    {
        dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
        event->accept();
    }
    if ( event->button() == Qt::RightButton )
    {
        this->close();
    }
}

void ShapeWidget::mouseMoveEvent( QMouseEvent *event )
{
    if ( event->buttons() & Qt::LeftButton )
    {
        this->move( event->globalPosition().toPoint() - dragPosition );
        event->accept();
    }
}

void ShapeWidget::paintEvent( QPaintEvent *event )
{
    QPainter painter( this );
    painter.drawPixmap( 0, 0, QPixmap( ":/Img/16.png" ) );
}
