#include "widget.h"

#include <QAbstractItemView>
#include <QAbstractitemModel>
#include <QApplication>
#include <QFileSystemModel>
#include <QItemSelectionModel>
#include <QListView>
#include <QSplitter>
#include <QTableView>
#include <QTreeView>

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );

    QFileSystemModel model;
    model.setRootPath( QDir::rootPath() );

    /*新建三种不同的 View 对象，以便文件目录可以以三种不同的方式显示*/
    QTreeView  tree;
    QListView  list;
    QTableView table;

    tree.setModel( &model );
    list.setModel( &model );
    table.setModel( &model );

    // 设置 QTreeView 的选择模式为多选
    tree.setSelectionMode( QAbstractItemView::MultiSelection );

    // 获取 QTreeView 的选择模型，并将其设置为 QListView 的选择模型
    QItemSelectionModel *treeSelectionModel = tree.selectionModel();
    list.setSelectionModel( treeSelectionModel );
    table.setSelectionModel( treeSelectionModel );

    // 连接 QTreeView 的双击信号到槽函数，以设置 QListView 的根索引
    QObject::connect( &tree, &QTreeView::doubleClicked,
                      [ &list, &tree, &table ]()
                      {
                          QModelIndex currentIndex = tree.currentIndex();
                          if ( currentIndex.isValid() )
                          {
                              list.setRootIndex( currentIndex );
                              table.setRootIndex( currentIndex );
                          }
                      } );

    QSplitter *splitter = new QSplitter;
    splitter->addWidget( &tree );
    splitter->addWidget( &list );
    splitter->addWidget( &table );
    splitter->setWindowTitle( QObject::tr( "Model/View" ) );
    splitter->show();
    return a.exec();
}
