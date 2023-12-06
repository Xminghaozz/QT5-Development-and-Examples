#ifndef MSGBOXDLG_H
#define MSGBOXDLG_H

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>

class MsgBoxDlg : public QDialog
{
  public:
    MsgBoxDlg( QWidget *parent = nullptr );
  private slots:
    void showQuestionMsg();
    void showInformationMsg();
    void showWarningMsg();
    void showCriticalMsg();
    void showAboutMsg();
    void showAboutQtMsg();

  private:
    QLabel      *label;
    QPushButton *questionBtn;
    QPushButton *informationBtn;
    QPushButton *warningBtn;
    QPushButton *criticalBtn;
    QPushButton *aboutBtn;
    QPushButton *aboutQtBtn;
    QGridLayout *mainLayout;
};

#endif // MSGBOXDLG_H
