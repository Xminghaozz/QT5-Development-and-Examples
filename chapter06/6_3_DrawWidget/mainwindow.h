#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "drawwidget.h"
#include <QComboBox>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QToolBar>
#include <QToolButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow( QWidget *parent = nullptr );
    ~MainWindow();
    void createToolBar();

  public slots:
    void showStyle();
    void showColor();

  private:
    DrawWidget  *drawWidget;
    QLabel      *styleLabel;
    QComboBox   *styleComboBox;
    QLabel      *widthLabel;
    QSpinBox    *widthSpinBox;
    QToolButton *colorBtn;
    QToolButton *clearBtn;
};
#endif // MAINWINDOW_H
