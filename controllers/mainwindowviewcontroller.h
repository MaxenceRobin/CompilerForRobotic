#ifndef MAINWINDOWVIEWCONTROLLER_H
#define MAINWINDOWVIEWCONTROLLER_H

// This inclusion goes first, to avoid the conflict between Qt "emit" keyword and the emit method of the Lexer class
#include "compilers/micropython/micropythoncompiler.h"

#include "views/mainwindow.h"

#include <QClipboard>

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
    void sendProgram();

private slots:
    void processBeforeQuitting();

private:
    MicroPythonCompiler microPythonCompiler;
    QClipboard* clipboard;

    ProgramFile testFile;
};

#endif // MAINWINDOWVIEWCONTROLLER_H
