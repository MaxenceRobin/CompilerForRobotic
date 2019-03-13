#ifndef MICROPYTHONGENERATOREXECUTOR_H
#define MICROPYTHONGENERATOREXECUTOR_H

// This include must go first because of the conflict between the emit method of Lexer and the Qt emit keyword
#include "compilers/micropython/micropythoncompiler.h"

#include "senders/wipy/wipysender.h"
#include "executors/abstractexecutor.h"

#include <QDir>
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
    virtual const QIcon getIcon() override;
    virtual const QString getToolTip() override;

private:
    bool initSenderPort();
    bool sendLibraries();

public slots:
    virtual void toggleDebugMode() override;

private slots:
    void translateManualCode();
    void startProgram();
    void stopProgram();

    void saveCode();

private:
    MicroPythonCompiler compiler;
    WipySender sender;
    QClipboard* clipboard;

    QDir libFolder;
    QString preProgramContent;
    QString postProgramContent;

    // Associated actions
    QAction startProgramAction;
    QAction stopProgramAction;

    // For debugging purpose
    QHBoxLayout layout;
    QTextEdit inputCode;
    QPushButton translateButton;
    QPushButton saveButton;
    QTextEdit outputCode;
};

#endif // MICROPYTHONGENERATOREXECUTOR_H
