#ifndef FLASHITEM_H
#define FLASHITEM_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>

class FlashItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
  public:
    explicit FlashItem( QObject *parent = nullptr );
    QRectF boundingRect() const;
    void   paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
    void   timerEvent( QTimerEvent *event );
  signals:
  public slots:
  private:
    bool    flash;
    QTimer *timer;
};

#endif // FLASHITEM_H
