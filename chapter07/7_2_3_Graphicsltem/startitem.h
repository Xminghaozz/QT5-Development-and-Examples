#ifndef STARTITEM_H
#define STARTITEM_H

#include <QGraphicsitem>
#include <QObject>
#include <QPainter>

class StartItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
  public:
    explicit StartItem( QObject *parent = nullptr );
    QRectF boundingRect() const;
    void   paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );

  signals:

  private:
    QPixmap pix;
};

#endif // STARTITEM_H
