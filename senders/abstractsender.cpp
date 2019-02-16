#include "abstractsender.h"

#include <QSerialPortInfo>

// Constructors and destructor --------------------------------------------------------------------
AbstractSender::AbstractSender()
    : portName("")
{
}


AbstractSender::~AbstractSender()
{
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Returns the list of all the available serial ports
 * @return A list of the names of all the available serial ports
 */
QStringList AbstractSender::getPortNameList()
{
    QStringList portNameList;
    const auto& portList = QSerialPortInfo::availablePorts();

    for (const auto& port : portList)
    {
        // The first valid port is chosed as the port on which to communicate
        if (!port.isNull())
        {
            portNameList << port.portName();
        }
    }

    return portNameList;
}

/**
 * @brief Changes the current serial port
 * @param portName : The name of the new serial port used
 */
void AbstractSender::setPort(const QString& newPortName)
{
    portName = newPortName;
}

/**
 * @brief Indicates which serial port is currently used, or an empyt string if none is defined yet
 * @return The name of the currently used port, or an empty string if no port is defined yet
 */
const QString& AbstractSender::getPortName() const
{
    return portName;
}
