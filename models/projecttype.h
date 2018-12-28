#ifndef PROJECTTYPE_H
#define PROJECTTYPE_H

#include "editors/baseeditor.h"
#include "executors/baseexecutor.h"

#include <QString>

/**
 * @brief Data storage class to represent a type of project
 */
template <class Editor, class Executor>
class ProjectType
{
public:
    ProjectType(const QString& _name, const QString& _extension, const QString& _icon = "");

    QString getName() const;
    QString getExtension() const;
    QString getIcon() const;
    BaseEditor* getNewEditor(const ProgramFile& file) const;
    BaseExecutor* getNewExecutor() const;

private:
    QString name;
    QString extension;
    QString icon;
};

// Class definition -------------------------------------------------------------------------------

/**
 * @brief Constructor of the ProjectType object
 * @param _name : The name of the project type, for display purpose only
 * @param _extension : The extension associated to files describing this type of project
 * @param _icon : The optionnal path to the icon representing the type of project, for display purpose only
 */
template <class Editor, class Executor>
ProjectType<Editor, Executor>::ProjectType(const QString& _name, const QString& _extension, const QString& _icon)
    : name(_name),
      extension(_extension),
      icon(_icon)
{
}

/**
 * @brief Returns the name of the project type
 * @return The name of the project type
 */
template <class Editor, class Executor>
QString ProjectType<Editor, Executor>::getName() const
{
    return name;
}

/**
 * @brief Returns the extension associated to this type of project
 * @return The extension associated to this type of project
 */
template <class Editor, class Executor>
QString ProjectType<Editor, Executor>::getExtension() const
{
    return extension;
}

/**
 * @brief Returns the path to the icon representing this type of project
 * @return The path to the icon representing this type of project
 */
template <class Editor, class Executor>
QString ProjectType<Editor, Executor>::getIcon() const
{
    return icon;
}

/**
 * @brief Returns a new editor associated to the given file
 * @return A new editor associated to the given file
 */
template <class Editor, class Executor>
BaseEditor* ProjectType<Editor, Executor>::getNewEditor(const ProgramFile& file) const
{
    return new Editor(file);
}

/**
 * @brief Returns a new executor
 * @return A new executor
 */
template <class Editor, class Executor>
BaseExecutor* ProjectType<Editor, Executor>::getNewExecutor() const
{
    return new Executor;
}

#endif // PROJECTTYPE_H
