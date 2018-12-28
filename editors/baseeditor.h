#ifndef BASEEDITOR_H
#define BASEEDITOR_H

#include "models/programfile.h"

#include <QWidget>

/**
 * @brief Base class for all the editors
 */
class BaseEditor : public QWidget
{
public:
    BaseEditor(ProgramFile& file);

    virtual QString getPivot() = 0;

protected:
    ProgramFile& getFile();

private:
    ProgramFile* programFile;
};

#endif // BASEEDITOR_H
