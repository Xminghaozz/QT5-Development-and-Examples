#ifndef PROGRESSDLG_H
#define PROGRESSDLG_H

#include <QComboBox>
#include <QDialog>
#include <QGridlayout>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>

class ProgressDlg : public QDialog
{
    Q_OBJECT

  public:
    ProgressDlg( QWidget *parent = nullptr );
    ~ProgressDlg();
  private slots:
    void startProgress();

  private:
    QLabel       *fileNum;
    QLineEdit    *fileNumLineEdit;
    QLabel       *progressType;
    QComboBox    *comboBox;
    QProgressBar *progressBar;
    QPushButton  *starBtn;
    QGridLayout  *mainLayout;
};
#endif // PROGRESSDLG_H
