#ifndef BASEEDITOR_H
#define BASEEDITOR_H

#include "models/programfile.h"

#include <QWidget>
#include <QAction>

/**
 * @brief Base class for all the editors
 */
class AbstractEditor : public QWidget
{
public:
    AbstractEditor(const QString& fileName);
    virtual ~AbstractEditor();

    const QList<QAction*>& getActions();

    ProgramFile& getFile();

    virtual QString getPivot() = 0;
    virtual void save();

public slots:
    virtual void toggleDebugMode() = 0;

private:
    ProgramFile programFile;
    QList<QAction*> actionsList;
};

#endif // BASEEDITOR_H
