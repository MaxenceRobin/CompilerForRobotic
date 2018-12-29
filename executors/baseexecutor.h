#ifndef BASEEXECUTOR_H
#define BASEEXECUTOR_H

#include <QWidget>

/**
 * @brief Base class for all executors
 */
class BaseExecutor : public QWidget
{
public:
    BaseExecutor();
    virtual ~BaseExecutor();

    virtual void execute(const QString& pivot) = 0;
};

#endif // BASEEXECUTOR_H
