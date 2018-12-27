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

// Special methods --------------------------------------------------------------------------------

/**
 * @brief Handles the event of closing the window
 * This method overrides the parent closeEvent method, to emit a signal that can be reused more easily
 * @param event : The info about the closing event
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
    emit closeRequested();
    QMainWindow::closeEvent(event);
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Grants access to the code input editor
 * @return The code input editor
 */
QTextEdit& MainWindow::getCodeInput()
{
    return *(ui->codeInput);
}

/**
 * @brief Grants access to the code output editor
 * @return The code output editor
 */
QTextEdit& MainWindow::getCodeOutput()
{
    return *(ui->codeOutput);
}

/**
 * @brief Grants access to the translation button
 * @return The translation button
 */
QPushButton& MainWindow::getTranslateButton()
{
    return *(ui->translateButton);
}

/**
 * @brief Grants access to the quit actino
 * @return The quit action
 */
QAction& MainWindow::getQuitAction()
{
    return *(ui->quitAction);
}

QWebEngineView& MainWindow::getWebView()
{
    return *(ui->webView);
}
