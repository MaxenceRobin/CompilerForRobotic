#ifndef PROJECTTYPELIST_H
#define PROJECTTYPELIST_H

#include "projecttype.h"

#include <QList>

/**
 * @brief Singleton class that contains all the existing project type and allows seeking operation over them
 */
class ProjectTypeList
{
public:
    static ProjectTypeList& getSingleton();
    ~ProjectTypeList();

    const QList<ProjectType<BaseEditor, BaseExecutor>*>& getTypesList() const;
    const ProjectType<BaseEditor, BaseExecutor> *getTypeByName(const QString& name) const;
    const ProjectType<BaseEditor, BaseExecutor> *getTypeByExtension(const QString& extension) const;

private:
    ProjectTypeList(); // Private for the singleton

    QList<ProjectType<BaseEditor, BaseExecutor>*> types;
};

#endif // PROJECTTYPELIST_H
