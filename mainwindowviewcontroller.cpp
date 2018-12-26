#include "mainwindowviewcontroller.h"

/**
 * @brief Constructor of the main controller
 */
MainWindowViewController::MainWindowViewController()
{
    // Settings

    // Connection
    connect(&getTranslateButton(), &QPushButton::clicked, this, &MainWindowViewController::translateCode);
}

/**
 * @brief Translate the pivot code into traget code
 * This method translate the pivot code into target code, by calling the compiler
 */
void MainWindowViewController::translateCode()
{
    getCodeOutput().setPlainText(getCodeInput().toPlainText());
}
