#ifndef WIPYSENDER_H
#define WIPYSENDER_H

#include "senders/abstractsender.h"

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
    void stop();
};

#endif // WIPYSENDER_H
