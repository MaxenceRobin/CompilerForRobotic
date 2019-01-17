#include "micropythongeneratorexecutor.h"

#include <QApplication>
#include <QDebug>

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

    // Settings
    inputCode.setFont(QFont("Consolas", 14));
    inputCode.setTabStopWidth(30);
    outputCode.setFont(QFont("Consolas", 14));
    outputCode.setTabStopWidth(30);

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

    const QString result = QString::fromStdString(
                compiler.getMicroPythonFromPivot(pivot.toStdString())
                );

    clipboard->setText(result);
    outputCode.setText(result);
}
