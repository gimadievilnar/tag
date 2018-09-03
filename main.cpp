#include "tag.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindows mainWdt;
    mainWdt.setWindowTitle("Пятнашки");
    mainWdt.show();
    return a.exec();
}
