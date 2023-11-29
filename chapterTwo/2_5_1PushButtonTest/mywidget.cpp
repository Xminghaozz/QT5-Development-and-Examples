#include "mywidget.h"
#include <qpushbutton.h>
#include <qfont.h>
#include <qapplication.h>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setMinimumSize(200,120);
    this->setMaximumSize(200,120);
    QPushButton *quit = new QPushButton("Quit",this);
    quit->setGeometry(62,40,75,30);
    quit->setFont(QFont("Times", 18, QFont::Bold));
    connect(quit,&QPushButton::clicked,qApp,&QApplication::quit);
}

MyWidget::~MyWidget()
{
}

