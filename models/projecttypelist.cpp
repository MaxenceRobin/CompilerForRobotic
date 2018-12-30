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
    types   << new ProjectType<BlocklyNeutralRobotEditor, MicroPythonGeneratorExecutor>("Blockly for MicroPython", "bkmp");
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
ProjectTypeList& ProjectTypeList::getSingleton()
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
