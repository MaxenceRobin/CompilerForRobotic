#ifndef PROJECTTYPE_H
#define PROJECTTYPE_H

#include "editors/baseeditor.h"
#include "executors/baseexecutor.h"

#include <QString>

/**
 * @brief Interface need to be able to store ProjectType object in a collection
 */
class AbstractProjectType
{
public:
    virtual QString getName() const = 0;
    virtual QString getExtension() const = 0;
    virtual QString getIcon() const = 0;
    virtual BaseEditor* getNewEditor(ProgramFile& file) const = 0;
    virtual BaseExecutor* getNewExecutor() const = 0;
};

/**
 * @brief Data storage class to represent a type of project
 */
template <class Editor, class Executor>
class ProjectType : public AbstractProjectType
{
public:
    ProjectType(const QString& _name, const QString& _extension, const QString& _icon = "");
    virtual ~ProjectType();

    virtual QString getName() const override;
    virtual QString getExtension() const override;
    virtual QString getIcon() const override;
    virtual BaseEditor* getNewEditor(ProgramFile &file) const override;
    virtual BaseExecutor* getNewExecutor() const override;

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
    : AbstractProjectType(),
      name(_name),
      extension(_extension),
      icon(_icon)
{
}

template <class Editor, class Executor>
ProjectType<Editor, Executor>::~ProjectType()
{
}

// Methods ----------------------------------------------------------------------------------------

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
BaseEditor* ProjectType<Editor, Executor>::getNewEditor(ProgramFile& file) const
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
