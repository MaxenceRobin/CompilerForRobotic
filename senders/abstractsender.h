#ifndef ABSTRACTSENDER_H
#define ABSTRACTSENDER_H

#include <QString>

/**
 * @brief This class represents an abstract sender that can scan the available serial ports and exchange data with an extern device
 */
class AbstractSender
{
public:
    AbstractSender();
    virtual ~AbstractSender();

    QStringList getPortNameList();
    void setPort(const QString& newPortName);
    const QString& getPortName() const;

protected:
    virtual bool execute(const QString& command) = 0;

private:
    QString portName;
};

#endif // ABSTRACTSENDER_H
