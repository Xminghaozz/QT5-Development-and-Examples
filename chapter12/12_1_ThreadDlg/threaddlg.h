#ifndef THREADDLG_H
#define THREADDLG_H

#include "workthread.h"
#include <QDialog>
#include <QPushButton>
#define MAXSIZE 10 // 宏定义线程的数目

class ThreadDlg : public QDialog
{
    Q_OBJECT

  public:
    ThreadDlg( QWidget *parent = nullptr );
    ~ThreadDlg();

  public slots:
    void slotStart(); // 启动线程
    void slotStop();  // 终止线程

  private:
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QPushButton *quitBtn;
    WorkThread  *workThread[ MAXSIZE ];
};
#endif // THREADDLG_H
