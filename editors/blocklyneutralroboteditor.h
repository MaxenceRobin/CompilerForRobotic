#ifndef BLOCKLYNEUTRALROBOTEDITOR_H
#define BLOCKLYNEUTRALROBOTEDITOR_H

#include "baseblocklyeditor.h"

/**
 * @brief An editor using the Blockly interface with blocks describing basic robot actions, not associated to a specific kind of robot
 */
class BlocklyNeutralRobotEditor : public BaseBlocklyEditor
{
public:
    BlocklyNeutralRobotEditor(const QString& fileName);
    virtual ~BlocklyNeutralRobotEditor();
};

#endif // BLOCKLYNEUTRALROBOTEDITOR_H
