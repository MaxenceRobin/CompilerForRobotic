#include "programfile.h"

#include <QTextStream>
#include <QDebug>

/**
 * @brief Constructor of the ProgramFile object
 * @param name : The name (path) of the file to open
 */
ProgramFile::ProgramFile(const QString& name)
    : QFile(name),
      content("")
{
    reloadFromDisk();
}

/**
 * @brief Destructor
 */
ProgramFile::~ProgramFile()
{
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Sets the content of the file
 * @param content : The new content of the file
 */
void ProgramFile::setContent(const QString &content)
{
    this->content = content;
}

/**
 * @brief Appends the content at the end of the file,
 * @param content : The content to add at the end of the file
 */
void ProgramFile::appendContent(const QString &content)
{
    this->content += content;
}

/**
 * @brief Gets the content of the file
 * @return The content of the file
 */
QString ProgramFile::getContent() const
{
    return content;
}

/**
 * @brief Reloads the content of the file from the disk and returns it, or return an empty string if the file couldn't be open
 * @return The content of the file from the disk, or an empty string if the file couldn't be open
 */
QString ProgramFile::reloadFromDisk()
{
    // The ReadWrite access is used to create the file if it doesn't exist (not available with ReadOnly)
    if (open(ProgramFile::Text | ProgramFile::ReadWrite))
    {
        content = readAll();
        close();
        return content;
    }

    return "";
}

/**
 * @brief Writes the content of the file onto the disk
 */
void ProgramFile::saveOnDisk()
{
    if (open(ProgramFile::Text | ProgramFile::WriteOnly))
    {
        QTextStream stream(this);
        stream << content;
        close();
    }
}
