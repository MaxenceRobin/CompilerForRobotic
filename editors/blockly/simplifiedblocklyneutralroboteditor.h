#ifndef SIMPLIFIEDBLOCKLYNEUTRALROBOTEDITOR_H
#define SIMPLIFIEDBLOCKLYNEUTRALROBOTEDITOR_H

#include "baseblocklyeditor.h"

class SimplifiedBlocklyNeutralRobotEditor : public BaseBlocklyEditor
{
public:
    SimplifiedBlocklyNeutralRobotEditor(const QString& fileName);
    virtual ~SimplifiedBlocklyNeutralRobotEditor() override;

public slots:
    virtual void toggleDebugMode() override;
};

#endif // SIMPLIFIEDBLOCKLYNEUTRALROBOTEDITOR_H
