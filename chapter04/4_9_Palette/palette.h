#ifndef PALETTE_H
#define PALETTE_H

#include <QComboBox>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

class Palette : public QDialog
{
    Q_OBJECT

  public:
    Palette( QWidget *parent = nullptr );
    ~Palette();
    void createCtrlFrame(); // 完成窗体左半部分颜色选择区的创建
    void createContentFrame();
    void fillColorList( QComboBox *comboBox ); // 完成向颜色下拉框中插入颜色的工作

  private slots:
    void showWindow();
    void showWindowText();
    void showButton();
    void showButtonText();
    void showBase();

  private:
    QFrame      *ctrlFrame; // 颜色选择面板
    QLabel      *windowLabel;
    QComboBox   *windowComboBox;
    QLabel      *windowTextLabel;
    QComboBox   *windowTextComboBox;
    QLabel      *buttonLabel;
    QComboBox   *buttonComboBox;
    QLabel      *buttonTextLabel;
    QComboBox   *buttonTextComboBox;
    QLabel      *baseLabel;
    QComboBox   *baseComboBox;
    QFrame      *contentFrame; // 具体显示面板
    QLabel      *label1;
    QComboBox   *comboBox1;
    QLabel      *label2;
    QLineEdit   *lineEdit2;
    QTextEdit   *textEdit;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
};
#endif // PALETTE_H
