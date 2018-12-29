#include "mainwindowviewcontroller.h"

#include "models/projecttypelist.h"

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
      clipboard(QApplication::clipboard()),
      testFile(URI("test/test.txt"))
{
    // Settings ---------------------------------

    const ProjectTypeList& list = ProjectTypeList::getSingleton();
    const AbstractProjectType* testType = list.getTypeByName("test");
    setEnvironment(testType->getNewEditor(testFile), testType->getNewExecutor());

    // Connections ------------------------------
    connect(&getSendAction(), &QAction::triggered, this, &MainWindowViewController::sendProgram);

    connect(&getQuitAction(), &QAction::triggered, this, &MainWindowViewController::close);
    connect(this, &MainWindowViewController::closeRequested, this, &MainWindowViewController::processBeforeQuitting);
}

/**
 * @brief Sends the program to the robot
 */
void MainWindowViewController::sendProgram()
{
}

/**
 * @brief Process important tasks before quitting the application
 */
void MainWindowViewController::processBeforeQuitting()
{
    // Things to do
    // ...
}

