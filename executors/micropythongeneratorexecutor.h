#ifndef MICROPYTHONGENERATOREXECUTOR_H
#define MICROPYTHONGENERATOREXECUTOR_H

// This include must go first because of the conflict between the emit method of Lexer and the Qt emit keyword
#include "compilers/micropython/micropythoncompiler.h"

#include "abstractexecutor.h"

#include <QClipboard>

#include <QHBoxLayout>
#include <QTextEdit>
#include <QPushButton>

/**
 * @brief Executor that produces MicroPython from abstract robotic pivot code and send it to the robot via serial port communication
 */
class MicroPythonGeneratorExecutor : public AbstractExecutor
{
    Q_OBJECT

public:
    MicroPythonGeneratorExecutor();
    virtual ~MicroPythonGeneratorExecutor() override;

    virtual void execute(const QString& pivot) override;

public slots:
    virtual void toggleDebugMode() override;

private slots:
    void translateManualCode();

private:
    MicroPythonCompiler compiler;
    QClipboard* clipboard;

    // For debugging purpose
    QHBoxLayout layout;
    QTextEdit inputCode;
    QPushButton translateButton;
    QTextEdit outputCode;
};

#endif // MICROPYTHONGENERATOREXECUTOR_H
