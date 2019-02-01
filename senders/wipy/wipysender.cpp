#include "wipysender.h"

/**
 * @brief WipySender::WipySender
 */
WipySender::WipySender()
    : QObject()
{
    connect(&process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), &blockingLoop, &QEventLoop::quit);
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Sends a file to the given location on the wipy card
 * @param file : The local file on the computer to send
 * @param location : The location on the wipy in which to send the file. This location may contain a file name that will represent the file on the wipy card
 */
void WipySender::send(const QString &file, const QString &location)
{
    // TODO : remplacer la sélection du port par une détection automatique
    const QString port = "COM3";

    // A first reset is done because the currenct execution has to be stopped before sending the new program
    process.start(
                QString("ampy --port %1 reset")
                .arg(port));

    blockingLoop.exec();

    // The new program is then sent
    process.start(
                QString("ampy --port %1 put %2 %3")
                .arg(port)
                .arg(file)
                .arg(location));

    blockingLoop.exec();
}
