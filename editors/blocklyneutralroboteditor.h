#ifndef BLOCKLYNEUTRALROBOTEDITOR_H
#define BLOCKLYNEUTRALROBOTEDITOR_H

#include "abstracteditor.h"

#include <QWebEngineView>
#include <QHBoxLayout>

/**
 * @brief An editor using the Blockly interface with blocks describing basic robot actions, not associated to a specific kind of robot
 */
class BlocklyNeutralRobotEditor : public AbstractEditor
{
public:
    BlocklyNeutralRobotEditor(ProgramFile& file);
    virtual ~BlocklyNeutralRobotEditor() override;

    virtual QString getPivot() override;

private:
    QHBoxLayout layout;
    QWebEngineView view;
};

#endif // BLOCKLYNEUTRALROBOTEDITOR_H
