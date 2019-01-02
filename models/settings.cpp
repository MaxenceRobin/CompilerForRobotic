#include "settings.h"

#include <QDebug>

#include <QApplication>
#define URI(path) QApplication::applicationDirPath() + "/" + path

/**
 * @brief Initialiazes the Settings object
 */
Settings::Settings()
    : QSettings(URI("Settings/settings.ini"), Settings::IniFormat)
{
    // Initialization
    qDebug() << fileName();

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

    setValue("defaultLocation", URI("Programs"));
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
