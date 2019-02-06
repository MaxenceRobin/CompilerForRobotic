#include "wipysender.h"

#include <QSerialPortInfo>
#include <QToolTip>
#include <QCursor>
#include <QDebug>

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
    QString portName = "";

    const auto& portList = QSerialPortInfo::availablePorts();

    for (const auto& port : portList)
    {

        // The first valid port is chosed as the port on which to communicate
        if (!port.isNull())
        {
            portName = port.portName();
            break;
        }
    }

    // If there is no port found, an error message is displayed and the program is not sent
    if (portName.isEmpty())
    {
        QToolTip::showText(QCursor::pos(), "Impossible d'envoyer le programme :\nAucune carte connectée");
        return;
    }

    // A first reset is done because the currenct execution has to be stopped before sending the new program
    QToolTip::showText(QCursor::pos(), "Envoi du programme... (0%)");
    process.start(
                QString("ampy --port %1 reset")
                .arg(portName));

    blockingLoop.exec();
    QToolTip::showText(QCursor::pos(), "Envoi du programme... (50%)");

    // The new program is then sent
    process.start(
                QString("ampy --port %1 put %2 %3")
                .arg(portName)
                .arg(file)
                .arg(location));

    blockingLoop.exec();
    QToolTip::showText(QCursor::pos(), "Envoi du programme terminé (100%)");
}
