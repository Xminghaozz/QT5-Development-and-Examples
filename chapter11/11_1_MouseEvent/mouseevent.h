#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include <QLabel>
#include <QMainWindow>
#include <QMouseEvent>
#include <QStatusBar>

class MouseEvent : public QMainWindow
{
    Q_OBJECT

  public:
    MouseEvent( QWidget *parent = nullptr );
    ~MouseEvent();

  protected:
    void mousePressEvent( QMouseEvent *e );
    void mouseMoveEvent( QMouseEvent *e );
    void mouseReleaseEvent( QMouseEvent *e );
    void mouseDoubleClickEvent( QMouseEvent *e );

  private:
    QLabel *statusLabel;
    QLabel *MousePosLabel;
};
#endif // MOUSEEVENT_H
