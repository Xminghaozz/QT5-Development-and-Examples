#include "keyevent.h"
#include <QPainter>

KeyEvent::KeyEvent( QWidget *parent )
    : QWidget( parent )
{
    this->setWindowTitle( tr( "键盘事件" ) );
    this->setAutoFillBackground( true );
    QPalette palette = this->palette();
    palette.setColor( QPalette::Window, Qt::white );
    this->setPalette( palette );

    this->setMinimumSize( 512, 256 );
    this->setMaximumSize( 512, 256 );
    this->width  = size().width();
    this->height = size().height();

    pix = new QPixmap( width, height );
    pix->fill( Qt::white );
    image.load( ":/Img/image.png" );
    startX = 100;
    startY = 100;
    step   = 20;
    this->drawPix();
    this->resize( 512, 256 );
}

KeyEvent::~KeyEvent() {}

void KeyEvent::drawPix()
{
    pix->fill( Qt::white );           // 重新刷新pix对象为白色底色
    QPainter *painter = new QPainter; // 创建一个QPainter对象
    QPen      pen( Qt::DotLine );

    for ( int i = step; i < width; i = i + step ) /// 按照步进值的间隔绘制纵向的网格线
    {
        painter->begin( pix ); // 指定pix为绘图设备
        painter->setPen( pen );
        painter->drawLine( QPoint( i, 0 ), QPoint( i, height ) );
        painter->end();
    }

    for ( int j = step; j < height; j = j + step )
    {
        painter->begin( pix );
        painter->setPen( pen );
        painter->drawLine( QPoint( 0, j ), QPoint( width, j ) );
        painter->end();
    }

    painter->begin( pix );
    painter->drawImage( QPoint( startX, startY ), image );
    painter->end();
}

void KeyEvent::keyPressEvent( QKeyEvent *event )
{
    if ( event->modifiers() == Qt::ControlModifier )
    {
        if ( event->key() == Qt::Key_Left )
        {
            startX = ( startX - 1 < 0 ? startX : startX - 1 );
        }
        if ( event->key() == Qt::Key_Right )
        {
            startX = ( startX + 1 + image.width() > width ? startX : startX + 1 );
        }
        if ( event->key() == Qt::Key_Up )
        {
            startY = ( startY - 1 < 0 ? startY : startY - 1 );
        }
        if ( event->key() == Qt::Key_Down )
        {
            startY = ( startY + 1 + image.height() > height ? startY : startY + 1 );
        }
    }
    else // 对Ctrl键没有按下的处理
    {
        /*首先调节图标左上顶点的位置至网格的顶点上*/
        startX = startX - startX % step;
        startY = startY - startY % step;
        if ( event->key() == Qt::Key_Left )
        {
            startX = ( startX - step < 0 ) ? startX : startX - step;
        }
        if ( event->key() == Qt::Key_Right )
        {
            startX = ( startX + step + image.width() > width ) ? startX : startX + step;
        }
        if ( event->key() == Qt::Key_Up )
        {
            startY = ( startY - step < 0 ) ? startY : startY - step;
        }
        if ( event->key() == Qt::Key_Down )
        {
            startY = ( startY + step + image.height() > height ) ? startY : startY + step;
        }
        if ( event->key() == Qt::Key_Home )
        {
            startX = 0;
            startY = 0;
        }
        if ( event->key() == Qt::Key_End )
        {
            startX = width - image.width();
            startY = height - image.height();
        }
    }

    this->drawPix(); // 根据调整后的图标位置重新在pix中绘制图像
    this->update();  // 触发界面重画
}

void KeyEvent::paintEvent( QPaintEvent * )
{
    QPainter painter;
    painter.begin( this );
    painter.drawPixmap( QPoint( 0, 0 ), *pix );
    painter.end();
}
