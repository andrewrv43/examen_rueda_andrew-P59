#include "showimc.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShowIMC w;
    w.show();
    return a.exec();
}
