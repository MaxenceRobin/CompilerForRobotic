#ifndef BASEEDITOR_H
#define BASEEDITOR_H

#include "models/programfile.h"

#include <QWidget>

/**
 * @brief Base class for all the editors
 */
class AbstractEditor : public QWidget
{
public:
    AbstractEditor(const QString& fileName);
    virtual ~AbstractEditor();

    ProgramFile& getFile();

    virtual QString getPivot() = 0;
    virtual void save();

public slots:
    virtual void toggleDebugMode() = 0;

private:
    ProgramFile programFile;
};

#endif // BASEEDITOR_H
