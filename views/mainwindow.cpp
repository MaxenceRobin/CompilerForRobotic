#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "editors/blocklyneutralroboteditor.h"
#include "models/projecttypelist.h"
#include "models/settings.h"

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
    currentFile(nullptr),
    projectOpen(false),
    createProgramDialog(this)
{
    ui->setupUi(this);

    // Initialization -------------------------------------
    setProjectMode(false);

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
    // If a file is currently open it it closed before quitting
    if (projectOpen)
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
 * @brief Enables ro disables the project mode (define which actions are visible or not)
 * @param mode : true to enabled to project mode, false to disable it
 */
void MainWindow::setProjectMode(bool mode)
{
    ui->createNewProgramAction->setEnabled(!mode);
    ui->openProgramAction->setEnabled(!mode);

    ui->closeProgramAction->setEnabled(mode);
    ui->saveAction->setEnabled(mode);
    ui->sendProgramAction->setEnabled(mode);
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
    setProjectMode(true);
}

// Slots ------------------------------------------------------------------------------------------

/**
 * @brief Opens a wizard to create a new program
 */
void MainWindow::createProgram()
{
    const QString fileName = createProgramDialog.getProgramFileName();

    if (!fileName.isEmpty())
    {
        loadProgram(fileName);
    }
}

/**
 * @brief Opens a wizard to open an exsiting program
 */
void MainWindow::openProgram()
{
    // Creating the filter list
    const ProjectTypeList& typesList = ProjectTypeList::getSingleton();
    QString filter = "";

    // The Qt filter format is :
    // "Name1 (*.ext1);;Name2 (*.ext2);;..."
    bool first = true;
    for (auto& type : typesList.getTypesList())
    {
        if (!first)
        {
            filter += ";;";
        }

        filter += type->getName() + " (*." + type->getExtension() + ")";
        first = false;
    }

    // Loading the opened file if the choice is not cancelled
    Settings& settings = Settings::getSingleton();
    const QString fileName = QFileDialog::getOpenFileName(this, "Ouvrir un programme", settings.value("defaultLocation").toString(), filter);

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
    saveProgram();
    replaceEnvironment(new QWidget, new QWidget);
    setProjectMode(false);
    projectOpen = false;
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
    AbstractEditor* currentEditor = dynamic_cast<AbstractEditor*>(editor);
    AbstractExecutor* currentExecutor = dynamic_cast<AbstractExecutor*>(executor);

    currentExecutor->execute(currentEditor->getPivot());
}
