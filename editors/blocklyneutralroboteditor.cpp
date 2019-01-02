#include "blocklyneutralroboteditor.h"

#include <QDebug>

#include <QApplication>
#define URI(path) QApplication::applicationDirPath() + "/" + path
#define BLOCKLY_NEUTRAL_ROBOT_PATH "Blockly/neutralrobot.html"

#define JS_COMMAND_GET_BLOCKLY_CODE "Blockly.JavaScript.workspaceToCode(workspace);"

/**
 * @brief Constructor of the editor
 * @param file : The file associated with the editor
 */
BlocklyNeutralRobotEditor::BlocklyNeutralRobotEditor(const QString& fileName)
    : AbstractEditor(fileName)
{
    // Initialization
    view.load(QUrl(URI(BLOCKLY_NEUTRAL_ROBOT_PATH)));
    layout.addWidget(&view);
    setLayout(&layout);
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
    view.page()->runJavaScript(JS_COMMAND_GET_BLOCKLY_CODE,
                               [this](const QVariant& value) { pivotResult = value.toString(); }
    );

    return pivotResult;
}

/**
 * @brief Saves the current file
 */
void BlocklyNeutralRobotEditor::save()
{
    // Storing the blockly blocks into the file content
    // ...
    AbstractEditor::save();
}
