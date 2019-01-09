#include "blocklyneutralroboteditor.h"

#define BLOCKLY_NEUTRAL_ROBOT_PATH "neutralrobot.html"

/**
 * @brief Constructor of the editor
 * @param file : The file associated with the editor
 */
BlocklyNeutralRobotEditor::BlocklyNeutralRobotEditor(const QString& fileName)
    : BaseBlocklyEditor(fileName, BLOCKLY_NEUTRAL_ROBOT_PATH)
{
}

/**
 * @brief Destructor
 */
BlocklyNeutralRobotEditor::~BlocklyNeutralRobotEditor()
{
}

