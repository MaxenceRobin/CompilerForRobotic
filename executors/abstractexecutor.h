#ifndef BASEEXECUTOR_H
#define BASEEXECUTOR_H

#include <QWidget>

/**
 * @brief Base class for all executors
 */
class AbstractExecutor : public QWidget
{
public:
    AbstractExecutor();
    virtual ~AbstractExecutor();

    virtual void execute(const QString& pivot) = 0;

public slots:
    virtual void toggleDebugMode() = 0;
};

#endif // BASEEXECUTOR_H
