#ifndef PROJECTTYPE_H
#define PROJECTTYPE_H

#include "editors/abstracteditor.h"
#include "executors/abstractexecutor.h"

#include <QString>

/**
 * @brief Interface need to be able to store ProjectType object in a collection
 */
class AbstractProjectType
{
public:
    AbstractProjectType(const QString& typeName, const QString& typeExtension, const QString& typeIcon = "");
    virtual ~AbstractProjectType();

    virtual QString getName() const;
    virtual QString getExtension() const;
    virtual QString getIcon() const;
    virtual AbstractEditor* getNewEditor(ProgramFile& file) const = 0;
    virtual AbstractExecutor* getNewExecutor() const = 0;

private:
    QString name;
    QString extension;
    QString icon;
};

// ProjectType ########################################################################################################
// ####################################################################################################################

/**
 * @brief Data storage class to represent a type of project
 */
template <class Editor, class Executor>
class ProjectType : public AbstractProjectType
{
public:
    ProjectType(const QString& name, const QString& extension, const QString& icon = "");
    virtual ~ProjectType() override;

    virtual AbstractEditor* getNewEditor(ProgramFile &file) const override;
    virtual AbstractExecutor* getNewExecutor() const override;
};

// Class definition -------------------------------------------------------------------------------

/**
 * @brief Constructor of the ProjectType object
 * @param name : The name of the project type, for display purpose only
 * @param extension : The extension associated to files describing this type of project
 * @param icon : The optionnal path to the icon representing the type of project, for display purpose only
 */
template <class Editor, class Executor>
ProjectType<Editor, Executor>::ProjectType(const QString& name, const QString& extension, const QString& icon)
    : AbstractProjectType(name, extension, icon)
{
}

/**
 * @brief Empty destructor
 */
template <class Editor, class Executor>
ProjectType<Editor, Executor>::~ProjectType()
{
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Returns a new editor associated to the given file
 * @return A new editor associated to the given file
 */
template <class Editor, class Executor>
AbstractEditor* ProjectType<Editor, Executor>::getNewEditor(ProgramFile& file) const
{
    return new Editor(file);
}

/**
 * @brief Returns a new executor
 * @return A new executor
 */
template <class Editor, class Executor>
AbstractExecutor* ProjectType<Editor, Executor>::getNewExecutor() const
{
    return new Executor;
}

#endif // PROJECTTYPE_H
