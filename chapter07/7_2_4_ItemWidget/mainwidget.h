#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "pixitem.h"
#include <QFrame>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>

class MainWidget : public QWidget
{
    Q_OBJECT

  public:
    MainWidget( QWidget *parent = nullptr );
    ~MainWidget();
    void createControlFrame();

  private:
    int            angle;
    qreal          scaleValue;
    qreal          shearValue;
    qreal          translateValue;
    QGraphicsView *view;
    QFrame        *ctrlFrame;
    PixItem       *pixItem;

  public slots:
    void slotRotate( int );
    void slotScale( int );
    void slotShear( int );
    void slotTranslate( int );
};
#endif // MAINWIDGET_H
