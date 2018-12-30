#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "editors/blocklyneutralroboteditor.h"

#include <QDebug>

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
    ui->closeProgramAction->setEnabled(false);
    ui->saveAction->setEnabled(false);
    ui->sendProgramAction->setEnabled(false);

    // Initialization of the environment
    editor = new QWidget;
    executor = new QWidget;
    ui->centralLayout->addWidget(editor);
    ui->centralLayout->addWidget(executor);

    // Connections
    connect(ui->quitAction, &QAction::triggered, this, &MainWindow::close);
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
    processBeforeQuitting();
    QMainWindow::closeEvent(event);
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Process the last things to do before quitting the application
 */
void MainWindow::processBeforeQuitting()
{
    // Things to do before quitting
}

/**
 * @brief Replaces the developpment environment with a new one, defined by an editor and an executor
 * @param newEditor : The new editor
 * @param newExecutor : The new executor
 */
void MainWindow::setEnvironment(AbstractEditor *newEditor, AbstractExecutor *newExecutor)
{
    replaceEnvironment(newEditor, newExecutor);

    // Changing the visible actions
    ui->createNewProgramAction->setEnabled(false);
    ui->openProgramAction->setEnabled(false);

    ui->closeProgramAction->setEnabled(true);
    ui->saveAction->setEnabled(true);
    ui->sendProgramAction->setEnabled(true);
}

/**
 * @brief Replaces the developpment environment with a new one, defined by two QWidget that are not specifically abstract editor or executor
 * @param newEditor : The new editor widget
 * @param newExecutor : The new executor widget
 */
void MainWindow::replaceEnvironment(QWidget *newEditor, QWidget *newExecutor)
{
    // Changing the environment
    ui->centralLayout->replaceWidget(editor, newEditor);
    ui->centralLayout->replaceWidget(executor, newExecutor);

    delete editor;
    delete executor;

    editor = newEditor;
    executor = newExecutor;
}
