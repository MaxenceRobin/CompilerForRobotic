#include "abstracteditor.h"

/**
 * @brief Constructor of the BaseEditor object
 * @param file
 */
AbstractEditor::AbstractEditor(ProgramFile &file)
    : QWidget(),
      programFile(&file)
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
 * @brief Grants access to the file for children
 * @return The internal ProgramFile object as a reference
 */
ProgramFile& AbstractEditor::getFile()
{
    return *programFile;
}
