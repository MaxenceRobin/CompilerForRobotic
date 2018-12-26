#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief Constructor of the main window
 * @param parent : The hierachical parent of the window
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/**
 * @brief Destructor of the main window
 */
MainWindow::~MainWindow()
{
    delete ui;
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Returns the code input area
 * @return the code input area
 */
QTextEdit& MainWindow::getCodeInput()
{
    return *ui->codeInput;
}

/**
 * @brief Returns the code output display
 * @return the code output display
 */
QTextEdit& MainWindow::getCodeOutput()
{
    return *ui->codeOutput;
}

/**
 * @brief Returns the translation button
 * @return The translation button
 */
QPushButton& MainWindow::getTranslateButton()
{
    return *ui->translateButton;
}
