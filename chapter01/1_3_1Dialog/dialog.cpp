#include "dialog.h"
#include "ui_dialog.h"

const static double PI=3.1416;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

// 点击计算按钮，计算圆的面积
void Dialog::on_countBtn_clicked()
{
    bool ok;
    QString tempStr;
    QString valueStr = ui->radiusLineEdit->text();
    int valueInt = valueStr.toInt(&ok);
    double area = valueInt*valueInt*PI;     // 计算圆面积
    ui->areaLabel_2->setText(tempStr.setNum(area));
}

// 在文本框输入半径，不需要点击计算按钮，直接显示圆的面积
void Dialog::on_radiusLineEdit_textChanged(const QString &arg1)
{
    bool ok;
    QString tempStr;
    QString valueStr = ui->radiusLineEdit->text();
    int valueInt = valueStr.toInt(&ok);
    double area =valueInt*valueInt*PI;      // 计算圆面积
    ui->areaLabel_2->setText(tempStr.setNum(area));
}

