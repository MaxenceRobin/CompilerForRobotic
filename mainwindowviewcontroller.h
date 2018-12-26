#ifndef MAINWINDOWVIEWCONTROLLER_H
#define MAINWINDOWVIEWCONTROLLER_H

#include "mainwindow.h"

/**
 * @brief The MainWindowViewController class
 * This class is the controller of the main window.
 */
class MainWindowViewController : public MainWindow
{
    Q_OBJECT

public:
    MainWindowViewController();

public slots:
    void translateCode();
};

#endif // MAINWINDOWVIEWCONTROLLER_H
