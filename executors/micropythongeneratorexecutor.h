#ifndef MICROPYTHONGENERATOREXECUTOR_H
#define MICROPYTHONGENERATOREXECUTOR_H

// This include must go first because of the conflict between the emit method of Lexer and the Qt emit keyword
#include "compilers/micropython/micropythoncompiler.h"

#include "baseexecutor.h"

#include <QClipboard>

/**
 * @brief
 */
class MicroPythonGeneratorExecutor : public BaseExecutor
{
public:
    MicroPythonGeneratorExecutor();
    virtual ~MicroPythonGeneratorExecutor() override;

    virtual void execute(const QString& pivot) override;

private:
    MicroPythonCompiler compiler;
    QClipboard* clipboard;
};

#endif // MICROPYTHONGENERATOREXECUTOR_H
