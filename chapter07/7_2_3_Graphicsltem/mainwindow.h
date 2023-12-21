#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsEllipseitem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QMenuBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow( QWidget *parent = nullptr );
    ~MainWindow();
    void initScene();     // 初始化场景
    void createActions(); // 创建主窗体的所有动作
    void createMenus();   // 创建主窗体的菜单栏

  public slots:
    void slotNew();              // 新建一个窗体
    void slotClear();            // 清除场景中所有的图元
    void slotAddEllipseItem();   // 在场景中加入一个椭圆形图元
    void slotAddPolygonItem();   // 在场景中加入一个多边形图元
    void slotAddTextItem();      // 在场景中加入一个图片文字
    void slotAddRectItem();      // 在场景中加入一个长方形图元
    void slotAddAlphaItem();     // 在场景中一个透明蝴蝶图片
    void slotAddFlashItem();     // 在场景中加入一个闪烁亮圆
    void slotAddAnimationItem(); // 在场景加入一个星星

  private:
    QGraphicsScene *scene;
    QAction        *newAct;
    QAction        *clearAct;
    QAction        *exitAct;
    QAction        *addEllipseItemAct;
    QAction        *addPolygonItemAct;
    QAction        *addTextItemAct;
    QAction        *addRectItemAct;
    QAction        *addAlphaItemAct;
    QAction        *addFlashItemAct;
    QAction        *addAnimItemAct;
};
#endif // MAINWINDOW_H
