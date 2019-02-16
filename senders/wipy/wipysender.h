#ifndef WIPYSENDER_H
#define WIPYSENDER_H

#include "senders/abstractsender.h"

#include <QString>
#include <QProcess>
#include <QEventLoop>

/**
 * @brief This class is used to send files to a Wipy esp32 card
 */
class WipySender : public AbstractSender
{
public:
    WipySender();

    void reset();
    bool put(const QString& file, const QString& location);
    QString get(const QString& file);
    QStringList list(const QString& location);

protected:
    virtual bool execute(const QString& command) override;

private:
    QProcess process;
    QEventLoop blockingLoop;
};

#endif // WIPYSENDER_H
