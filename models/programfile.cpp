#include "programfile.h"

#include <QDataStream>

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
 * @brief Destructor of the object, close automatically the file if it's still open
 */
ProgramFile::~ProgramFile()
{
    if (isOpen())
    {
        close();
    }
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Sets the content of the file, if it is open
 * @param content : The new content of the file
 */
void ProgramFile::setContent(const QString &content)
{
    if (isOpen())
    {
        this->content = content;
    }
}

/**
 * @brief Appends the content at the end of the file, if it is open
 * @param content : The content to add at the end of the file
 */
void ProgramFile::appendContent(const QString &content)
{
    if (isOpen())
    {
        this->content += content;
    }
}

/**
 * @brief Gets the content of the file, or an empty string if it is not open
 * @return The content of the file, or an empty string if it is not open
 */
QString ProgramFile::getContent() const
{
    if (isOpen())
    {
        return content;
    }
    else
    {
        return "";
    }
}

/**
 * @brief Reloads the content of the file from the disk and returns it, or return an empty string if the file couldn't be open
 * @return The content of the file from the disk, or an empty string if the file couldn't be open
 */
QString ProgramFile::reloadFromDisk()
{
    if (!isOpen())
    {
        open(ProgramFile::Text | ProgramFile::ReadWrite);
    }
    else
    {
        reset();
    }

    if (isOpen())
    {
        content = readAll();
        return content;
    }
    else
    {
        return "";
    }
}

/**
 * @brief Writes the content of the file onto the disk, if the file is open
 */
void ProgramFile::saveOnDisk()
{
    if (isOpen())
    {
        QDataStream stream(this);
        stream << content;
    }
}
