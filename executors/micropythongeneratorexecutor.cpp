#include "micropythongeneratorexecutor.h"

#include <QApplication>
#include <QDebug>

MicroPythonGeneratorExecutor::MicroPythonGeneratorExecutor()
    : AbstractExecutor(),
      clipboard(QApplication::clipboard())
{
    hide();
}

/**
 * @brief Destructor
 */
MicroPythonGeneratorExecutor::~MicroPythonGeneratorExecutor()
{
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Translate the pivot code into MicroPython and set it into the clipboard to be pasted
 * @param pivot : The pivot code to work on
 */
void MicroPythonGeneratorExecutor::execute(const QString &pivot)
{
    const QString result = QString::fromStdString(
                compiler.getMicroPythonFromPivot(pivot.toStdString())
                );

    clipboard->setText(result);
}
