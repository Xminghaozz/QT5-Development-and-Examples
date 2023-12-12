#ifndef IMGPROCESSOR_H
#define IMGPROCESSOR_H

#include "showwidget.h"
#include <QAction>
#include <QApplication>
#include <QComboBox>
#include <QImage>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QSpinBox>
#include <QTextCharFormat>
#include <QToolBar>
#include <QToolButton>
#include <QfontComboBox>

class ImgProcessor : public QMainWindow
{
    Q_OBJECT

  public:
    ImgProcessor( QWidget *parent = nullptr );
    ~ImgProcessor();
    void createActions();  // 创建动作
    void createMenus();    // 创建菜单
    void createToolBars(); // 创建工具栏
    void loadFile( QString fileName );
    void mergeFormat( QTextCharFormat );

  protected slots:
    void showNewFile();
    void showOpenFile();
    void showPrintText();
    void showPrintImage();
    void showZoomIn();
    void showZoomOut();
    void showRotate90();
    void showRotate180();
    void showRotate270();
    void showMirrorVertical();
    void showMirrorHorizontal();

  private:
    QMenu      *fileMenu;
    QMenu      *zoomMenu;
    QMenu      *rotateMenu;
    QMenu      *mirrorMenu;
    QImage      img;
    QString     fileName;
    ShowWidget *showWidget;
    QAction    *openFileAction; // 文件菜单项
    QAction    *NewFileAction;
    QAction    *PrintTextAction;
    QAction    *PrintImageAction;
    QAction    *exitAction;
    QAction    *copyAction; // 编辑菜单项
    QAction    *cutAction;
    QAction    *pasteAction;
    QAction    *aboutAction;
    QAction    *zoomInAction;
    QAction    *zoomOutAction;
    QAction    *rotate90Action; // 旋转菜单项
    QAction    *rotate180Action;
    QAction    *rotate270Action;
    QAction    *mirrorVerticalAction; // 镜像菜单项
    QAction    *mirrorHorizontalAction;
    QAction    *undoAction;
    QAction    *redoAction;
    QToolBar   *fileTool; // 工具栏
    QToolBar   *zoomTool;
    QToolBar   *rotateTool;
    QToolBar   *mirrorTool;
    QToolBar   *doToolBar;
};
#endif // IMGPROCESSOR_H
