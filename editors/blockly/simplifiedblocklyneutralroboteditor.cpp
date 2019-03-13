#include "simplifiedblocklyneutralroboteditor.h"

#define BLOCKLY_SIMPLIFIED_NEUTRAL_ROBOT_PATH "simplifiedneutralrobot.html"

// Concstructors and destructor -------------------------------------------------------------------

/**
 * @brief Constructor of the editor
 * @param fileName : The associated file of the editor
 */
SimplifiedBlocklyNeutralRobotEditor::SimplifiedBlocklyNeutralRobotEditor(const QString& fileName)
    : BaseBlocklyEditor(fileName, BLOCKLY_SIMPLIFIED_NEUTRAL_ROBOT_PATH)
{
}

/**
 * @brief Destructor
 */
SimplifiedBlocklyNeutralRobotEditor::~SimplifiedBlocklyNeutralRobotEditor()
{
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Toggles the debug mode
 */
void SimplifiedBlocklyNeutralRobotEditor::toggleDebugMode()
{
    //setVisible(isHidden());
}
