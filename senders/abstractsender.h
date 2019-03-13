#ifndef ABSTRACTSENDER_H
#define ABSTRACTSENDER_H

#include <QString>

#include <QProcess>
#include <QEventLoop>

/**
 * @brief This class represents an abstract sender that can scan the available serial ports and exchange data with an extern device
 */
class AbstractSender
{
public:
    AbstractSender();
    virtual ~AbstractSender();

    virtual bool execute(const QString& command);

    QStringList getPortNameList();
    void setPort(const QString& newPortName);
    const QString& getPortName() const;

protected:
    QProcess process;
    QEventLoop blockingLoop;

private:
    QString portName;
};

#endif // ABSTRACTSENDER_H
