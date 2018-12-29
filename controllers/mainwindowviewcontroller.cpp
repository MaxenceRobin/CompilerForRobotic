#include "mainwindowviewcontroller.h"

#include <QAction>
#include <QDebug>

#include <QApplication>
#define URI(path) QApplication::applicationDirPath() + "/" + path

#define JS_COMMAND_GET_BLOCKLY_CODE "Blockly.JavaScript.workspaceToCode(workspace);"

/**
 * @brief Constructor of the main controller
 */
MainWindowViewController::MainWindowViewController()
    : MainWindow(),
      clipboard(QApplication::clipboard())
{
    // Settings ---------------------------------
    getWebView().load(QUrl(URI("Blockly/neutralrobot.html")));

    // The debug mode is setted to off by default
    toggleDebugMode();

    // Connections ------------------------------
    connect(&getTranslateButton(), &QPushButton::clicked, this, &MainWindowViewController::translateCode);
    connect(&getSendAction(), &QAction::triggered, this, &MainWindowViewController::sendProgram);

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
    const QString result = QString::fromStdString(microPythonCompiler.compile(getCodeInput().toPlainText().toStdString()));

    getCodeOutput().setPlainText(result);
    clipboard->setText(result);
}

/**
 * @brief Sends the program to the robot
 */
void MainWindowViewController::sendProgram()
{
    QTextEdit& codeInput = getCodeInput();

    // Trying to get the code from blockly
    getWebView().page()->runJavaScript(JS_COMMAND_GET_BLOCKLY_CODE,
                                       [&codeInput](const QVariant& value) { codeInput.setPlainText(value.toString()); }
                                       );
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
    getCodeOutput().setHidden(visibility);
}

