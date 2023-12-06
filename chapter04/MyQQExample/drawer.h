#ifndef DRAWER_H
#define DRAWER_H

#include <QApplication>
#include <QFlags>
#include <QToolBox>

class Drawer : public QToolBox
{
  public:
    Drawer( QWidget *parent = nullptr, Qt::WindowFlags f = 0 );
};

#endif // DRAWER_H
