#ifndef PROGRAMFILE_H
#define PROGRAMFILE_H

#include <QFile>
#include <QString>

/**
 * @brief Improved version of the QFile class
 */
class ProgramFile : public QFile
{
public:
    ProgramFile(const QString& name);
    ~ProgramFile();

    void setContent(const QString& content);
    void appendContent(const QString& content);
    QString getContent() const;
    QString reloadFromDisk();
    void saveOnDisk();

private:
    QString content;
    bool is;

};

#endif // PROGRAMFILE_H
