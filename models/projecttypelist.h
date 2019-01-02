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
    static const ProjectTypeList& getSingleton();
    ~ProjectTypeList();

    const QList<AbstractProjectType*>& getTypesList() const;
    const AbstractProjectType *getTypeByName(const QString& name) const;
    const AbstractProjectType *getTypeByExtension(const QString& extension) const;
    const QString getNameByExtension(const QString& extension) const;
    const QString getExtensionByName(const QString& name) const;

private:
    ProjectTypeList(); // Private for the singleton

    QList<AbstractProjectType*> types;
};

#endif // PROJECTTYPELIST_H
