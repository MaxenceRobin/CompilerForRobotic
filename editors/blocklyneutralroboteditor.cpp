#include "blocklyneutralroboteditor.h"

#include <QApplication>
#define URI(path) QApplication::applicationDirPath() + "/" + path
#define BLOCKLY_NEUTRAL_ROBOT_PATH "Blockly/neutralrobot.html"

#define JS_COMMAND_GET_BLOCKLY_CODE "Blockly.JavaScript.workspaceToCode(workspace);"

#define JS_COMMAND_GET_BLOCKLY_BLOCKS   "var xml = Blockly.Xml.workspaceToDom(workspace);"\
                                        "Blockly.Xml.domToPrettyText(xml);"

#define JS_COMMAND_SET_BLOCKLY_BLOCKS   "Blockly.Xml.domToWorkspace(Blockly.Xml.textToDom(Blockly.fileContent), workspace);"

/**
 * @brief Constructor of the editor
 * @param file : The file associated with the editor
 */
BlocklyNeutralRobotEditor::BlocklyNeutralRobotEditor(const QString& fileName)
    : AbstractEditor(fileName),
      channel(view.page())
{
    view.page()->setWebChannel(&channel);
    channel.registerObject("dataGetter", new Channel(getFile().getContent()));

    // Initialization
    view.load(QUrl(URI(BLOCKLY_NEUTRAL_ROBOT_PATH)));
    layout.addWidget(&view);
    setLayout(&layout);

    // Connections
    connect(&view, &QWebEngineView::loadFinished, this, &BlocklyNeutralRobotEditor::loadProgram);
}

/**
 * @brief Loads the program into Blockly once the page is loaded
 */
void BlocklyNeutralRobotEditor::loadProgram()
{
    // Loading the blockly file
    QString command = QString(JS_COMMAND_SET_BLOCKLY_BLOCKS);
    view.page()->runJavaScript(command);
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
    view.page()->runJavaScript(JS_COMMAND_GET_BLOCKLY_CODE, [this](const QVariant& value)
    {
        pivotResult = value.toString();
    });

    return pivotResult;
}

/**
 * @brief Saves the current file
 */
void BlocklyNeutralRobotEditor::save()
{
    // Storing the blockly blocks into the file content
    view.page()->runJavaScript(QString(JS_COMMAND_GET_BLOCKLY_BLOCKS), [this] (const QVariant& value)
    {
        getFile().setContent(value.toString());
    });

    AbstractEditor::save();
}
