#include "stackdlg.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Stackdlg w;
    w.show();
    return a.exec();
}
