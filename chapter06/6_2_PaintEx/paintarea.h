#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QBrush>
#include <QPen>
#include <QWidget>

class PaintArea : public QWidget
{
    Q_OBJECT
  public:
    explicit PaintArea( QWidget *parent = nullptr );
    enum Shape
    {
        Line,
        Rectangle,
        RoundRect,
        Ellipse,
        Polygon,
        Polyline,
        Points,
        Arc,
        Path,
        Text,
        Pixmap
    };
    void setShape( Shape );
    void setPen( QPen );
    void setBrush( QBrush );
    void setFillRule( Qt::FillRule );
    void paintEvent( QPaintEvent * );

  signals:

  public slots:

  private:
    Shape        shape;
    QPen         pen;
    QBrush       brush;
    Qt::FillRule fillRule;
};

#endif // PAINTAREA_H
