#include "networkinfomation.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NetworkInfomation w;
    w.show();
    return a.exec();
}
