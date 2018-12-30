#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "editors/blocklyneutralroboteditor.h"
#include "models/projecttypelist.h"

#include <QFileInfo>
#include <QFileDialog>

#include <QDebug>

/**
 * @brief Constructor of the main window
 * @param parent : The hierachical parent of the window
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentFile(nullptr)
{
    ui->setupUi(this);

    // Initialization -------------------------------------
    // Actions
    ui->closeProgramAction->setEnabled(false);
    ui->saveAction->setEnabled(false);
    ui->sendProgramAction->setEnabled(false);

    // Environment
    editor = new QWidget;
    executor = new QWidget;
    ui->centralLayout->addWidget(editor);
    ui->centralLayout->addWidget(executor);

    // Connections ----------------------------------------
    connect(ui->quitAction, &QAction::triggered, this, &MainWindow::close);

    connect(ui->createNewProgramAction, &QAction::triggered, this, &MainWindow::createProgram);
    connect(ui->openProgramAction, &QAction::triggered, this, &MainWindow::openProgram);
    connect(ui->closeProgramAction, &QAction::triggered, this, &MainWindow::closeProgram);
    connect(ui->saveAction, &QAction::triggered, this, &MainWindow::saveProgram);
    connect(ui->sendProgramAction, &QAction::triggered, this, &MainWindow::sendProgram);
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
    // If a file is currently open, the current program is closed first (even though the file will be deleted by the linked destruction anyway)
    if (currentFile != nullptr)
    {
        closeProgram();
    }
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

    // The previous widgets have to be deleted
    delete editor;
    delete executor;

    editor = newEditor;
    executor = newExecutor;
}

/**
 * @brief Loads the editor and the executor for the given file
 * @param fileName : The program file to load
 */
void MainWindow::loadProgram(const QString &fileName)
{
    const ProjectTypeList& typesList = ProjectTypeList::getSingleton();
    QFileInfo info(fileName);
    const QString extension = info.suffix();

    // We get the associated project type, to get the corresponding editor and executor
    // We also get the ProgramFile associated to the editor and store it
    const AbstractProjectType* projectType = typesList.getTypeByExtension(extension);

    if (projectType == nullptr)
    {
        return;
    }

    AbstractEditor* newEditor = projectType->getNewEditor(fileName);
    AbstractExecutor* newExecutor = projectType->getNewExecutor();
    currentFile = &newEditor->getFile();

    // The editor and executor are setted
    replaceEnvironment(newEditor, newExecutor);

    // Finally the appropriate actions are enabled or disabled
    ui->createNewProgramAction->setEnabled(false);
    ui->openProgramAction->setEnabled(false);

    ui->closeProgramAction->setEnabled(true);
    ui->saveAction->setEnabled(true);
    ui->sendProgramAction->setEnabled(true);
}

// Slots ------------------------------------------------------------------------------------------

/**
 * @brief Opens a wizard to create a new program
 */
void MainWindow::createProgram()
{

}

/**
 * @brief Opens a wizard to open an exsiting program
 */
void MainWindow::openProgram()
{
    // Creating the filter list
    const ProjectTypeList& typesList = ProjectTypeList::getSingleton();
    QString filter = "";

    for (auto& type : typesList.getTypesList())
    {
        filter += type->getName() + " (*." + type->getExtension() + ");;";
    }

    // Loading the opened file if the choice is not cancelled
    const QString fileName = QFileDialog::getOpenFileName(this, "Ouvrir un programme", "", filter);

    if (!fileName.isNull())
    {
        loadProgram(fileName);
    }
}

/**
 * @brief Closes the currently open program
 */
void MainWindow::closeProgram()
{
    replaceEnvironment(new QWidget, new QWidget);

    ui->createNewProgramAction->setEnabled(true);
    ui->openProgramAction->setEnabled(true);

    ui->closeProgramAction->setEnabled(false);
    ui->saveAction->setEnabled(false);
    ui->sendProgramAction->setEnabled(false);
}

/**
 * @brief Saves the currently open program
 */
void MainWindow::saveProgram()
{
    currentFile->saveOnDisk();
}

/**
 * @brief Sends the pivot code generated by the editor to the executor
 */
void MainWindow::sendProgram()
{
}
