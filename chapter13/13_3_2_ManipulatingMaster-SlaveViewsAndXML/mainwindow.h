#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDomDocument>
#include <QDomNode>
#include <QFile>
#include <QGroupBox>
#include <QLabel>
#include <QListWidget>
#include <QMainWindow>
#include <QModelIndex>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>
#include <QTableView>

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow( const QString &factoryTable, const QString &carTable, QFile *carDetails,
                QWidget *parent = nullptr );
    ~MainWindow();

  private:
    QGroupBox *createCarGroupBox();
    QGroupBox *createFactoryGroupBox();
    QGroupBox *createDetailsGroupBox();
    void       createMenuBar();

    QTableView  *carView;
    QTableView  *factoryView;
    QListWidget *attribList; // 显示车型的详细信息列表

    /*声明相关的信息标签*/
    QLabel *profileLabel;
    QLabel *titleLabel;

    void        decreaseCarCount( QModelIndex index );
    void        getAttribList( QDomNode car );
    QModelIndex indexOfFactory( const QString &factory );
    void        readCarData();
    void        removeCarFromDatabase( QModelIndex index );
    void        removeCarFromFile( int id );

    QDomDocument              carData;
    QFile                    *file;
    QSqlRelationalTableModel *carModel;
    QSqlTableModel           *factoryModel;

  private slots:
    void addCar();
    void changeFactory( QModelIndex index );
    void delCar();
    void showCarDetails( QModelIndex index );
    void showFactoryProfile( QModelIndex index );
};
#endif // MAINWINDOW_H
