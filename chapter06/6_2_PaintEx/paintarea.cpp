#include "paintarea.h"

#include <QPainter>
#include <QPainterPath>

PaintArea::PaintArea( QWidget *parent )
    : QWidget{ parent }
{
    this->setPalette( QPalette( Qt::white ) );
    this->setAutoFillBackground( true );
    this->setMinimumSize( 400, 400 );
}

void PaintArea::setShape( Shape s )
{
    shape = s;
    this->update();
}

void PaintArea::setPen( QPen p )
{
    pen = p;
    this->update();
}

void PaintArea::setBrush( QBrush b )
{
    brush = b;
    this->update();
}

void PaintArea::setFillRule( Qt::FillRule rule )
{
    fillRule = rule;
    this->update(); // 重画绘制区窗体
}

void PaintArea::paintEvent( QPaintEvent * )
{
    QPainter p( this );  // 新建一个QPainter对象
    p.setPen( pen );     // 设置QPainter对象的画笔
    p.setBrush( brush ); // 设置QPainter对象的画刷
    QRect               rect( 50, 100, 300, 200 );
    static const QPoint points[ 4 ] = { QPoint( 150, 100 ), QPoint( 300, 150 ), QPoint( 350, 250 ),
                                        QPoint( 100, 300 ) };

    int          startAngle = 30 * 16;
    int          spanAngle  = 120 * 16;
    QPainterPath path; // 新建一个 QPainterPath 对象为画路径做准备
    path.addRect( 150, 150, 100, 100 );
    path.moveTo( 100, 100 );
    path.cubicTo( 300, 100, 200, 200, 300, 300 );
    path.cubicTo( 100, 300, 200, 200, 100, 100 );
    path.setFillRule( fillRule );

    switch ( shape )
    {
    case Line: // 直线
        p.drawLine( rect.topLeft(), rect.bottomRight() );
        break;
    case Rectangle: // 长方形
        p.drawRect( rect );
        break;
    case RoundRect: // 圆角方形
        p.drawRoundedRect( rect, 20, 20 );
        break;
    case Ellipse: // 椭圆形
        p.drawEllipse( rect );
        break;
    case Polygon: // 多边形
        p.drawPolygon( points, 4 );
        break;
    case Polyline: // 多边线
        p.drawPolyline( points, 4 );
        break;
    case Points: // 点
        p.drawPoints( points, 4 );
        break;
    case Arc: // 弧
        p.drawArc( rect, startAngle, spanAngle );
        break;
    case Path: // 路径
        p.drawPath( path );
        break;
    case Text: // 文字
        p.drawText( rect, Qt::AlignCenter, tr( "Hello Qt!" ) );
        break;
    case Pixmap: // 图片
        p.drawPixmap( 150, 150, QPixmap( ":/Img/image.png" ) );
        break;
    default:
        break;
    }
}
