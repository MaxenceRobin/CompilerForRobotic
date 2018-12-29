#include "blocklyneutralroboteditor.h"

#include <QApplication>
#define URI(path) QApplication::applicationDirPath() + "/" + path
#define BLOCKLY_NEUTRAL_ROBOT_PATH "Blockly/neutralrobot.html"

#define JS_COMMAND_GET_BLOCKLY_CODE "Blockly.JavaScript.workspaceToCode(workspace);"

/**
 * @brief Constructor of the editor
 * @param file : The file associated with the editor
 */
BlocklyNeutralRobotEditor::BlocklyNeutralRobotEditor(ProgramFile &file)
    : BaseEditor(file)
{
    view.load(QUrl(URI(BLOCKLY_NEUTRAL_ROBOT_PATH)));
}

/**
 * @brief Destructor
 */
BlocklyNeutralRobotEditor::~BlocklyNeutralRobotEditor()
{
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Returns the pivot code associated to the blockly program
 * @return The pivot code for the current blockly program
 */
QString BlocklyNeutralRobotEditor::getPivot()
{
    QString result;

    view.page()->runJavaScript(JS_COMMAND_GET_BLOCKLY_CODE,
                               [&result](const QVariant& value) { result = value.toString(); }
    );

    return result;
}
