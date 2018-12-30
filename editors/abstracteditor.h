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
    AbstractEditor(ProgramFile& file);
    virtual ~AbstractEditor();

    virtual QString getPivot() = 0;

protected:
    ProgramFile& getFile();

private:
    ProgramFile* programFile;
};

#endif // BASEEDITOR_H
