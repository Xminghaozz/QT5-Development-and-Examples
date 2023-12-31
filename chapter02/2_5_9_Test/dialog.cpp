#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QRegularExpression regExp("[A-Za-z][1-9][0-9]{0,2}");   // 正则表达式限制输入字元的范围
    ui->lineEdit->setValidator(new QRegularExpressionValidator(regExp,this));
    connect(ui->okButton,&QPushButton::clicked,this,&QDialog::accept);
    connect(ui->cancelButton,&QPushButton::clicked,this,&QDialog::reject);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_lineEdit_textChanged()
{
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}
