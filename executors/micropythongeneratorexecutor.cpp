#include "micropythongeneratorexecutor.h"

#include "models/programfile.h"
#include <QFile>

#include <QApplication>
#include <QDebug>

#define GENERATION(name) QApplication::applicationDirPath() + "/Generation/" + name

/**
 * @brief Constructor of the executor
 */
MicroPythonGeneratorExecutor::MicroPythonGeneratorExecutor()
    : AbstractExecutor(),
      clipboard(QApplication::clipboard())
{
    hide();

    // Initialization of the debugging elements
    translateButton.setText("->");

    layout.addWidget(&inputCode);
    layout.addWidget(&translateButton);
    layout.addWidget(&outputCode);

    setLayout(&layout);

    // Loading of the pre program content
    QFile preProgramContentFile(":/generators/micropython/preprogramcontent");

    if (preProgramContentFile.open(QFile::Text | QFile::ReadOnly))
    {
        preProgramContent = preProgramContentFile.readAll();
        preProgramContentFile.close();
    }

    // Settings
    inputCode.setFont(QFont("Consolas", 14));
    inputCode.setTabStopDistance(30);
    outputCode.setFont(QFont("Consolas", 14));
    outputCode.setTabStopDistance(30);

    // Connections
    connect(&translateButton, &QPushButton::clicked, this, &MicroPythonGeneratorExecutor::translateManualCode);
}

/**
 * @brief Destructor
 */
MicroPythonGeneratorExecutor::~MicroPythonGeneratorExecutor()
{
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Toggles the debug mode
 */
void MicroPythonGeneratorExecutor::toggleDebugMode()
{
    setVisible(isHidden());
}

/**
 * @brief Used in debug mode to translate and display a code written directly by the user
 */
void MicroPythonGeneratorExecutor::translateManualCode()
{
    execute(inputCode.toPlainText());
}

/**
 * @brief Translate the pivot code into MicroPython and set it into the clipboard to be pasted
 * @param pivot : The pivot code to work on
 */
void MicroPythonGeneratorExecutor::execute(const QString &pivot)
{
    inputCode.setText(pivot);

    QString result = QString::fromStdString(
                compiler.getMicroPythonFromPivot(pivot.toStdString())
                );

    clipboard->setText(result);
    outputCode.setText(result);

    result = preProgramContent + "\n" + result;

    // Creation of the source file to be copied on the Wipy card
    ProgramFile sourceFile(GENERATION("main.py"));
    sourceFile.setContent(result);
    sourceFile.saveOnDisk();


    // Sending the program to the card
    sender.send(GENERATION("main.py"), "/flash/main.py");
}
