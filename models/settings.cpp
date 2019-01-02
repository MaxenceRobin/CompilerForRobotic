#include "settings.h"

#include <QDebug>
#include <QDir>

#include <QApplication>
#define URI(path) QApplication::applicationDirPath() + "/" + path

// Definitions ------------------------------------------------------------------------------------

#define DEFAULT_PROGRAM_LOCATION "defaultProgramLocation"

// Implementation ---------------------------------------------------------------------------------

/**
 * @brief Initialiazes the Settings object
 */
Settings::Settings()
    : QSettings(URI("Settings/settings.ini"), Settings::IniFormat)
{
    // If no settings are defined yet, the default settings have to be initialized
    if (!value("isDefined", false).toBool())
    {
        init();
    }
}

/**
 * @brief Initializes the default settings if none are defined
 */
void Settings::init()
{
    setValue("isDefined", true);

    setValue(DEFAULT_PROGRAM_LOCATION, URI("Programs"));
}

/**
 * @brief Returns the uniq instance of Settings using the singleton pattern
 * @return The uniq instance of Settings object
 */
Settings& Settings::getSingleton()
{
    static Settings instance;
    return instance;
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Returns the default program location
 * @return the default program location
 */
QString Settings::getDefaultProgramLocation()
{
    Settings& instance = getSingleton();

    // If the default location doesn't exist anymore, its value is resetted
    QDir defaultLocation(instance.value(DEFAULT_PROGRAM_LOCATION).toString());

    if (!defaultLocation.exists())
    {
        instance.setValue(DEFAULT_PROGRAM_LOCATION, URI("Programs"));
    }

    return instance.value(DEFAULT_PROGRAM_LOCATION).toString();
}

/**
 * @brief Sets the default program location
 * @param location : The new default program location
 */
void Settings::setDefaultProgramLocation(const QString &location)
{
    Settings& instance = getSingleton();
    instance.setValue(DEFAULT_PROGRAM_LOCATION, location);
}
