#include "baseeditor.h"

/**
 * @brief Constructor of the BaseEditor object
 * @param file
 */
BaseEditor::BaseEditor(ProgramFile &file)
    : QWidget(),
      programFile(&file)
{
}

/**
 * @brief Destructor of the BaseEditor object
 */
BaseEditor::~BaseEditor()
{
    // The program file object is destroyed outside of this class
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Grants access to the file for children
 * @return The internal ProgramFile object as a reference
 */
ProgramFile& BaseEditor::getFile()
{
    return *programFile;
}
