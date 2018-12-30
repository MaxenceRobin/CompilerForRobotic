#include "projecttype.h"

/**
 * @brief Creates an abstract type with the given name, extension and icon
 * @param typeName : The name of the project type, for display purpose
 * @param typeExtension : The extensions of files associated with this project type
 * @param typeIcon : The path to the icon representing this project type, for display purpose
 */
AbstractProjectType::AbstractProjectType(const QString& typeName, const QString& typeExtension, const QString& typeIcon)
    : name(typeName),
      extension(typeExtension),
      icon(typeIcon)
{
}

/**
 * @brief Empty destructor
 */
AbstractProjectType::~AbstractProjectType()
{
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Returns the name of the project type
 * @return The name of the project type
 */
QString AbstractProjectType::getName() const
{
    return name;
}

/**
 * @brief Returns the extension associated to this type of project
 * @return The extension associated to this type of project
 */
QString AbstractProjectType::getExtension() const
{
    return extension;
}

/**
 * @brief Returns the path to the icon representing this type of project
 * @return The path to the icon representing this type of project
 */
QString AbstractProjectType::getIcon() const
{
    return icon;
}
