#ifndef BLOCKLYNEUTRALROBOTEDITOR_H
#define BLOCKLYNEUTRALROBOTEDITOR_H

#include "baseeditor.h"

#include <QWebEngineView>

/**
 * @brief An editor using the Blockly interface with blocks describing basic robot actions, not associated to a specific kind of robot
 */
class BlocklyNeutralRobotEditor : public BaseEditor
{
public:
    BlocklyNeutralRobotEditor(ProgramFile& file);
    virtual ~BlocklyNeutralRobotEditor() override;

    virtual QString getPivot() override;

private:
    QWebEngineView view;
};

#endif // BLOCKLYNEUTRALROBOTEDITOR_H