#ifndef INPUTDLG_H
#define INPUTDLG_H

#include <QDialog>
#include <QGridLayout>
#include <QInputDialog>
#include <QLabel>
#include <QPushButton>

class InputDlg : public QDialog
{
  public:
    InputDlg( QWidget *parent = nullptr );
  public slots:
    void changeName();
    void changeSex();
    void changeAge();
    void changeScore();

  private:
    QLabel      *nameLabel1;
    QLabel      *sexLabel1;
    QLabel      *ageLabel1;
    QLabel      *scoreLabel1;
    QLabel      *nameLabel2;
    QLabel      *sexLabel2;
    QLabel      *ageLabel2;
    QLabel      *scoreLabel2;
    QPushButton *nameBtn;
    QPushButton *sexBtn;
    QPushButton *ageBtn;
    QPushButton *scoreBtn;
    QGridLayout *mainLayout;
};

#endif // INPUTDLG_H
