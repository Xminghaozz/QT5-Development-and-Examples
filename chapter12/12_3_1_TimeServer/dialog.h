#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>

class TimeServer;

class Dialog : public QDialog   //服务器端界面类
{
    Q_OBJECT

  public:
    Dialog( QWidget *parent = nullptr );
    ~Dialog();

  public slots:
    void slotShow();

  private:
    QLabel      *label1;     // 此标签用于监听端口
    QLabel      *label2;     // 此标签用于显示请求次数
    QPushButton *quitBtn;    // 退出按钮
    TimeServer  *timeserver; // TCP 服务器端 timeserver
    int          count;      // 请求次数计数器
};
#endif // DIALOG_H
