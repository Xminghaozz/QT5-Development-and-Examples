#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void on_lineEdit_textChanged();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
