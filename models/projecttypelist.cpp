// This include must go first because it is dependant of the MicroPythonCompiler file
#include "executors/micropythongeneratorexecutor.h"

#include "projecttypelist.h"

#include "editors/blocklyneutralroboteditor.h"

/**
 * @brief Constructor of the list
 */
ProjectTypeList::ProjectTypeList()
{
    // Creation of the types
    types   << new ProjectType<BlocklyNeutralRobotEditor, MicroPythonGeneratorExecutor>("Blockly for MicroPython", "bkmp", ":/icons/blocklyneutralrobot");
}

/**
 * @brief Destructor. Destroys all the created types
 */
ProjectTypeList::~ProjectTypeList()
{
    for (auto& type : types)
    {
        delete type;
    }
}

/**
 * @brief Returns the uniq instance of ProjectTypeList
 * @return The ProjectTypeList singleton
 */
const ProjectTypeList &ProjectTypeList::getSingleton()
{
    static ProjectTypeList list;
    return list;
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Returns the list of all the existing project types
 * @return All the existing project types
 */
const QList<AbstractProjectType*>& ProjectTypeList::getTypesList() const
{
    return types;
}

/**
 * @brief Returns the project type with the corresponding name
 * @param name : The name of the seeked project type
 * @return The project type with the corresponding name
 */
const AbstractProjectType* ProjectTypeList::getTypeByName(const QString &name) const
{
    for (auto& type : types)
    {
        if (type->getName() == name)
        {
            return type;
        }
    }

    return nullptr;
}

/**
 * @brief Returns the project type with the corresponding extension
 * @param extension : The extension of the seeked project type
 * @return The project type with the corresponding extension
 */
const AbstractProjectType* ProjectTypeList::getTypeByExtension(const QString &extension) const
{
    for (auto& type : types)
    {
        if (type->getExtension() == extension)
        {
            return type;
        }
    }

    return nullptr;
}

/**
 * @brief Convenience method that returns the name of a type from its extension
 * @param extension : The extension of the seeked type
 * @return The name of the type having the given extension
 */
const QString ProjectTypeList::getNameByExtension(const QString &extension) const
{
    const AbstractProjectType* type = getTypeByExtension(extension);
    return type->getName();
}

/**
 * @brief Convenience method that returns the extension of a type from its name
 * @param name : The name of the seeked type
 * @return The extensions of the type having the given extension
 */
const QString ProjectTypeList::getExtensionByName(const QString &name) const
{
    const AbstractProjectType* type = getTypeByName(name);
    return type->getExtension();
}
