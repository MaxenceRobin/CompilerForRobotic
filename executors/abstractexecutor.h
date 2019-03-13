#ifndef BASEEXECUTOR_H
#define BASEEXECUTOR_H

#include <QWidget>
#include <QAction>
#include <QIcon>

/**
 * @brief Base class for all executors
 */
class AbstractExecutor : public QWidget
{
public:
    AbstractExecutor();
    virtual ~AbstractExecutor();

    virtual void execute(const QString& pivot) = 0;
    virtual const QIcon getIcon() = 0;
    virtual const QString getToolTip() = 0;
    const QList<QAction *>& getActions();

protected:
    void showMessage(const QString& message, const QString& color = "black", const QString& size = "15pt");

public slots:
    virtual void toggleDebugMode() = 0;

protected:
    QList<QAction*> actionsList;
};

#endif // BASEEXECUTOR_H
