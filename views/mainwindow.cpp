#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "editors/blocklyneutralroboteditor.h"

/**
 * @brief Constructor of the main window
 * @param parent : The hierachical parent of the window
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Settings

    // Initialization of the environment
    editor = new QWidget;
    executor = new QWidget;
    ui->centralLayout->addWidget(editor);
    ui->centralLayout->addWidget(executor);
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
 * @brief Grants access to the quit actino
 * @return The quit action
 */
QAction& MainWindow::getQuitAction()
{
    return *(ui->quitAction);
}

/**
 * @brief Grants access to the program sending action
 * @return The program sending action
 */
QAction& MainWindow::getSendAction()
{
    return *(ui->sendProgramAction);
}

/**
 * @brief Replaces the developpment environment with a new one, defined by an editor and an executor
 * @param newEditor : The new editor
 * @param newExecutor : The new executor
 */
void MainWindow::setEnvironment(BaseEditor *newEditor, BaseExecutor *newExecutor)
{
    QWidget* oldEditor = editor;
    QWidget* oldExecutor = executor;

    ui->centralLayout->replaceWidget(oldEditor, newEditor);
    ui->centralLayout->replaceWidget(oldExecutor, newExecutor);

    delete oldEditor;
    delete oldExecutor;

    editor = newEditor;
    executor = newExecutor;
}
