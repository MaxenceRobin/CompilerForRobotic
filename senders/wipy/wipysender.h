#ifndef WIPYSENDER_H
#define WIPYSENDER_H

#include <QObject>
#include <QString>
#include <QProcess>
#include <QEventLoop>

/**
 * @brief This class is used to send files to a Wipy esp32 card
 * Is assumes that only one Wipy card is connected to the computer
 */
class WipySender : public QObject
{
    Q_OBJECT

public:
    WipySender();

    void send(const QString& file, const QString& location);

private:
    QProcess process;
    QEventLoop blockingLoop;
};

#endif // WIPYSENDER_H
