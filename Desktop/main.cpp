#include "widget.h"
#include <QApplication>
#include <settingsdialog.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
//    SettingsDialog b;
//    b.show();

    return a.exec();
}
