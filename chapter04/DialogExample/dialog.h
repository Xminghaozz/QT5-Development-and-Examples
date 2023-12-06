#ifndef DIALOG_H
#define DIALOG_H

#include "inputdlg.h"
#include "msgboxdlg.h"

#include <QColorDialog>
#include <QDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

  public:
    Dialog( QWidget *parent = nullptr );
    ~Dialog();
  public slots:
    void showFile();
    void showColor();
    void showFont();
    void showInputDlg();
    void showMsgDlg();
    void showCustomDlg();

  private:
    QPushButton *fileBtn;
    QLineEdit   *fileLineEdit;
    QGridLayout *mainLayout;

    QPushButton *colorBtn;
    QFrame      *colorFrame;

    QPushButton *fontBtn;
    QLineEdit   *fontLineEdit;

    QPushButton *inputBtn;
    InputDlg    *inputDlg;

    QPushButton *msgBtn;
    MsgBoxDlg   *msgDlg;

    QPushButton *customBtn;
    QLabel      *label;
};
#endif // DIALOG_H
