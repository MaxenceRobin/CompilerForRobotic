#include "mainwindowviewcontroller.h"

#include <QAction>
#include <QDebug>

#include <QApplication>
#define URI(path) QApplication::applicationDirPath() + "/" + path

/**
 * @brief Constructor of the main controller
 */
MainWindowViewController::MainWindowViewController()
    : MainWindow()
{
    // Settings ---------------------------------
    getWebView().load(QUrl(URI("Blockly/main.html")));

    // The debug mode is setted to off by default
    toggleDebugMode();

    // Connections ------------------------------
    connect(&getTranslateButton(), &QPushButton::clicked, this, &MainWindowViewController::translateCode);

    connect(&getQuitAction(), &QAction::triggered, this, &MainWindowViewController::close);
    connect(this, &MainWindowViewController::closeRequested, this, &MainWindowViewController::processBeforeQuitting);

    connect(&getDebugModeAction(), &QAction::triggered, this, &MainWindowViewController::toggleDebugMode);
}

/**
 * @brief Translate the pivot code into traget code
 * This method translate the pivot code into target code, by calling the compiler
 */
void MainWindowViewController::translateCode()
{
    getCodeOutput().setPlainText(
                QString::fromStdString(
                    microPythonCompiler.compile(getCodeInput().toPlainText().toStdString())
                    )
                );
}

/**
 * @brief Sends the program to the robot
 */
void MainWindowViewController::sendProgram()
{
    // Trying to get the code from blockly
    translateCode();
}

/**
 * @brief Process important tasks before quitting the application
 */
void MainWindowViewController::processBeforeQuitting()
{
    // Things to do
    // ...
}

/**
 * @brief Toggle the visibility of the code input editor and the translate button
 */
void MainWindowViewController::toggleDebugMode()
{
    const bool visibility = !getCodeInput().isHidden();

    getCodeInput().setHidden(visibility);
    getTranslateButton().setHidden(visibility);
}

