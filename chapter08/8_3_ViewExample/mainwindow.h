#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "histogramview.h"
#include <QAction>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QSplitter>
#include <QStandardItemModel>
#include <QTableView>
class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow( QWidget *parent = 0 );
    ~MainWindow();
    void createAction();
    void createMenu();
    void setupModel();
    void setupView();
    void openFile( QString );
  public slots:
    void slotOpen();

  private:
    QMenu              *fileMenu;
    QAction            *openAct;
    QStandardItemModel *model;
    QTableView         *table;
    QSplitter          *splitter;
    HistogramView      *histogram;
};

#endif // MAINWINDOW_H
