#include "drawwidget.h"

DrawWidget::DrawWidget( QWidget *parent )
    : QWidget{ parent }
{
    this->setAutoFillBackground( true ); // 对窗体背景颜色的设置
    this->setPalette( QPalette( Qt::white ) );
    pix = new QPixmap( size() );      // 此 QPixmap 对象用于准备随时接收绘制的内容
    pix->fill( Qt::white );           /// 填充背景色为白色
    this->setMinimumSize( 600, 400 ); // 设置绘制窗体的最小尺寸
}

void DrawWidget::mousePressEvent( QMouseEvent *e )
{
    startPos = e->pos(); // 按下鼠标时，记录当前鼠标位置
}

void DrawWidget::mouseMoveEvent( QMouseEvent *e )
{
    QPainter *painter = new QPainter; // 新建一个QPainter对象
    QPen      pen;                    // 新建一个QPen对象
    pen.setStyle( (Qt::PenStyle) style );
    pen.setWidth( weight ); // 设置画笔的线宽值
    pen.setColor( color );  // 设置画笔的颜色
    painter->begin( pix );
    painter->setPen( pen ); // 将QPen对象应用到绘制对象中

    // 绘制从startPos到鼠标当前位置的直线
    painter->drawLine( startPos, e->pos() );
    painter->end();
    startPos = e->pos(); // 更新鼠标位置，为下次绘制做准备
    this->update();      // 重绘绘制区窗体
}

void DrawWidget::paintEvent( QPaintEvent * )
{
    QPainter painter( this );
    painter.drawPixmap( QPoint( 0, 0 ), *pix );
}

void DrawWidget::resizeEvent( QResizeEvent *event )
{
    if ( height() > pix->height() || width() > pix->width() )
    {
        QPixmap *newPix = new QPixmap( size() ); // 创建一个新QPixmap对象
        newPix->fill( Qt::white ); // 创新 QPixmap 对象 newPix 的颜色为白色背景色
        QPainter p( newPix );
        p.drawPixmap( QPoint( 0, 0 ), *pix ); // 在 newPix 中绘制原 pix 中的内容
        pix = newPix; // 将 newPix 赋值给 pix 作为新的绘制图形接收对象
    }
    QWidget::resizeEvent( event ); // 完成其余的工作
}

void DrawWidget::setStyle( int s ) { style = s; }

void DrawWidget::setWidth( int w ) { weight = w; }

void DrawWidget::setColor( QColor c ) { color = c; }

void DrawWidget::clear()
{
    QPixmap *clearPix = new QPixmap( size() );
    clearPix->fill( Qt::white );
    pix = clearPix;
    update();
}
