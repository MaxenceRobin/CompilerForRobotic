#include "projecttypelist.h"

#include "editors/blocklyneutralroboteditor.h"

#include "executors/micropythongeneratorexecutor.h"

/**
 * @brief Constructor of the list
 */
ProjectTypeList::ProjectTypeList()
{
    // Creation of the types
    types   << new ProjectType<BlocklyNeutralRobotEditor, MicroPythonGeneratorExecutor>("test", "tst", "osef");
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

const QList<ProjectTypeInterface*> &ProjectTypeList::getTypesList() const
{
    return types;
}

/**
 * @brief Returns the project type with the corresponding name
 * @param name : The name of the seeked project type
 * @return The project type with the corresponding name
 */
const ProjectTypeInterface* ProjectTypeList::getTypeByName(const QString &name) const
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
const ProjectTypeInterface* ProjectTypeList::getTypeByExtension(const QString &extension) const
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
