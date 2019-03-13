#include "wipysender.h"

#include <QObject>
#include <QFileInfo>
#include <QDebug>

/**
 * @brief WipySender::WipySender
 */
WipySender::WipySender()
    : AbstractSender()
{
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Resets the card
 */
void WipySender::reset()
{
    execute(QString("ampy --port %1 reset")
            .arg(getPortName()));
}

/**
 * @brief Sends a file to the given location on the wipy card
 * @param file : The local file on the computer to send
 * @param location : The location on the wipy in which to send the file. This location may contain a file name that will represent the file on the wipy card
 * @return 'true' if the sending was successful, 'false' otherwise
 */
bool WipySender::put(const QString &file, const QString &location)
{
    bool result = execute(QString("ampy --port %1 put %2 %3")
                   .arg(getPortName())
                   .arg(file)
                   .arg(location));

    return result;
}

/**
 * @brief Returns the content of a file on the wipy card
 * @param file : The file on the wipy card for which to get the content
 * @return The content of the specified file
 */
QString WipySender::get(const QString &file)
{
    execute(QString("ampy --port %1 get %2")
            .arg(getPortName())
            .arg(file));

    return process.readAllStandardOutput();
}

/**
 * @brief Returns the list of all present files on the wipy card at the given location
 * @param location : The location on the wipy card for which to get the list of files
 * @return The list of files at the specified location on the wipy card
 */
QStringList WipySender::list(const QString &location)
{
    execute(QString("ampy --port %1 ls %2")
            .arg(getPortName())
            .arg(location));

    QString processOutput = process.readAllStandardOutput();
    QStringList filesList = processOutput.split("\r\n", QString::SkipEmptyParts);

    // The location of the file is included in its name, so we have to remove it and keep only the last part of the returned path
    for (auto& file : filesList)
    {
        // We use QFileInfo::fileName() method to directly get the file name corresponding to the given file location
        file = QFileInfo(file).fileName();
    }

    return filesList;
}

/**
 * @brief Stop the current process
 */
void WipySender::stop()
{
    blockingLoop.quit();
}
