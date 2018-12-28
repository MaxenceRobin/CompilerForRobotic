#include "baseeditor.h"

/**
 * @brief Constructor of the BaseEditor object.
 * @param file
 */
BaseEditor::BaseEditor(ProgramFile &file)
    : QWidget(),
      programFile(&file)
{
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
