#include "baseblocklyeditor.h"

#include <QEventLoop>

#include <QApplication>
#define BLOCKLY(name) QApplication::applicationDirPath() + "/Blockly/" + name


#define JS_COMMAND_GET_BLOCKLY_CODE "Blockly.JavaScript.workspaceToCode(workspace);"

#define JS_COMMAND_GET_BLOCKLY_BLOCKS   "var xml = Blockly.Xml.workspaceToDom(workspace);"\
                                        "Blockly.Xml.domToPrettyText(xml);"

#define JS_COMMAND_SET_BLOCKLY_BLOCKS   "Blockly.Xml.domToWorkspace(Blockly.Xml.textToDom(Blockly.fileContent), workspace);"

/**
 * @brief Constructor of the editor
 * @param file : The file associated with the editor
 */
BaseBlocklyEditor::BaseBlocklyEditor(const QString& fileName, const QString &blocklyFile)
    : AbstractEditor(fileName),
      channel(view.page())
{
    view.page()->setWebChannel(&channel);
    channel.registerObject("dataGetter", this);

    // Initialization
    view.load(QUrl(BLOCKLY(blocklyFile)));
    layout.addWidget(&view);
    setLayout(&layout);

    // Connections
    connect(&view, &QWebEngineView::loadFinished, this, &BaseBlocklyEditor::loadProgram);

    connect(this, &BaseBlocklyEditor::endLoop, &blockingLoop, &QEventLoop::quit);
}

/**
 * @brief Loads the program into Blockly once the page is loaded
 */
void BaseBlocklyEditor::loadProgram()
{
    // Loading the blockly file
    QString command = QString(JS_COMMAND_SET_BLOCKLY_BLOCKS);
    view.page()->runJavaScript(command);
}

/**
 * @brief Destructor
 */
BaseBlocklyEditor::~BaseBlocklyEditor()
{
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Does nothing. The implementation only avoid sub classes to be forced to implement it
 */
void BaseBlocklyEditor::toggleDebugMode()
{
}

/**
 * @brief Returns the pivot code associated to the blockly program
 * @return The pivot code for the current blockly program
 */
QString BaseBlocklyEditor::getPivot()
{
    view.page()->runJavaScript(JS_COMMAND_GET_BLOCKLY_CODE, [this](const QVariant& value)
    {
        pivotResult = value.toString();
        emit endLoop();
    });

    blockingLoop.exec();

    return pivotResult;
}

/**
 * @brief Saves the current file
 */
void BaseBlocklyEditor::save()
{
    // Storing the blockly blocks into the file content
    view.page()->runJavaScript(QString(JS_COMMAND_GET_BLOCKLY_BLOCKS), [this] (const QVariant& value)
    {
        getFile().setContent(value.toString());
        emit endLoop();
    });

    blockingLoop.exec();

    AbstractEditor::save();
}

/**
 * @brief Returns the content of the intern file. This method is used for the javascript to access the content of the saved blockly file
 * @return The content of the intern file
 */
QString BaseBlocklyEditor::getFileContent()
{
    return getFile().getContent();
}
