#include "abstracteditor.h"

/**
 * @brief Constructor of the BaseEditor object
 * @param file
 */
AbstractEditor::AbstractEditor(const QString &fileName)
    : QWidget(),
      programFile(fileName)
{
}

/**
 * @brief Destructor of the BaseEditor object
 */
AbstractEditor::~AbstractEditor()
{
    // The program file object is destroyed outside of this class
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Returns the list of associated actions of the editor
 * @return The list of the associated actions of the editor
 */
const QList<QAction*>& AbstractEditor::getActions()
{
    return actionsList;
}

/**
 * @brief Grants access to the file
 * @return The internal ProgramFile object as a reference
 */
ProgramFile& AbstractEditor::getFile()
{
    return programFile;
}

/**
 * @brief Saves the intern file on the disk
 */
void AbstractEditor::save()
{
    programFile.saveOnDisk();
}
