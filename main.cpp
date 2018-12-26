#include "mainwindowviewcontroller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindowViewController window;
    window.showMaximized();

    return app.exec();
}
