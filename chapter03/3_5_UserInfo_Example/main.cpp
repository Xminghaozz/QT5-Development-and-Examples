#include "content.h"

#include <QApplication>
#include <QSplitter>
#include <QListWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("AR PL KaitiM GB",12);       // 设置整个程序使用的字体字号
    a.setFont(font);
    // 新建一个水平分割对象窗口，作为主布局框
    QSplitter *splitterMain = new QSplitter(Qt::Horizontal,nullptr);
    splitterMain->setOpaqueResize(true);
    QListWidget *list = new QListWidget(splitterMain);
    list->insertItem(0,QObject::tr("基本信息"));
    list->insertItem(1,QObject::tr("联系方式"));
    list->insertItem(2,QObject::tr("详细资料"));

    Content *content = new Content(splitterMain);
    QObject::connect(list,&QListWidget::currentRowChanged,content->stack,&QStackedWidget::setCurrentIndex);

    //设置主布局框即水平分割窗口的标题
    splitterMain->setWindowTitle(QObject::tr(" 修改用户资料")) ;
    //设置主布局框即水平分割窗口的最小尺寸
    splitterMain->setMinimumSize (splitterMain->minimumSize ());
    //设置主布局框即水平分割窗口的最大尺寸
    splitterMain->setMaximumSize (splitterMain->maximumSize ());
    splitterMain->show () ;              //显示主布局框，其上面的控件一同显示
    // Content w;
    // w.show();
    return a.exec();
}
