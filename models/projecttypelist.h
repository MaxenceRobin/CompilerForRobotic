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

    const QList<ProjectTypeInterface*>& getTypesList() const;
    const ProjectTypeInterface *getTypeByName(const QString& name) const;
    const ProjectTypeInterface *getTypeByExtension(const QString& extension) const;

private:
    ProjectTypeList(); // Private for the singleton

    QList<ProjectTypeInterface*> types;
};

#endif // PROJECTTYPELIST_H
