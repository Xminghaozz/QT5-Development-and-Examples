#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QPainter>

class Butterfly : public QObject, public QGraphicsItem
{
    Q_OBJECT
  public:
    explicit Butterfly( QObject *parent = nullptr );
    void   timerEvent( QTimerEvent   *);
    QRectF boundingRect() const;

  signals:

  public slots:

  protected:
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget ); // 重绘函数

  private:
    bool    up;
    QPixmap pix_up; // 用于表示两幅蝴蝶的图片
    QPixmap pix_down;
    qreal   angle;
};

#endif // BUTTERFLY_H
