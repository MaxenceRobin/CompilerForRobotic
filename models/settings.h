#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

/**
 * @brief This class represents the settings of the application, accessible from anywhere with the singleton pattern
 */
class Settings : public QSettings
{
public:
    static Settings& getSingleton();

private:
    // Private for the singleton
    Settings();
    void init();
};

#endif // SETTINGS_H
