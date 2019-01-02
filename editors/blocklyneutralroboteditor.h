#ifndef BLOCKLYNEUTRALROBOTEDITOR_H
#define BLOCKLYNEUTRALROBOTEDITOR_H

#include "abstracteditor.h"

#include <QWebEngineView>
#include <QHBoxLayout>
#include <QString>

/**
 * @brief An editor using the Blockly interface with blocks describing basic robot actions, not associated to a specific kind of robot
 */
class BlocklyNeutralRobotEditor : public AbstractEditor
{
public:
    BlocklyNeutralRobotEditor(const QString &fileName);
    virtual ~BlocklyNeutralRobotEditor() override;

    virtual QString getPivot() override;

private:
    QHBoxLayout layout;
    QWebEngineView view;

    QString pivotResult;
};

#endif // BLOCKLYNEUTRALROBOTEDITOR_H
