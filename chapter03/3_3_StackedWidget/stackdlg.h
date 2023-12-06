#ifndef STACKDLG_H
#define STACKDLG_H

#include <QDialog>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QHBoxLayout>

class Stackdlg : public QDialog
{
    Q_OBJECT

public:
    Stackdlg(QWidget *parent = nullptr);
    ~Stackdlg();

private:
    QListWidget *list;
    QStackedWidget *stack;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;

};
#endif // STACKDLG_H
