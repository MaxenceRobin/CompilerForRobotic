#ifndef BLOCKLYNEUTRALROBOTEDITOR_H
#define BLOCKLYNEUTRALROBOTEDITOR_H

#include "abstracteditor.h"

#include <QWebEngineView>
#include <QHBoxLayout>
#include <QString>
#include <QWebChannel>
#include <QDebug>

class Channel;

/**
 * @brief An editor using the Blockly interface with blocks describing basic robot actions, not associated to a specific kind of robot
 */
class BlocklyNeutralRobotEditor : public AbstractEditor
{
    Q_OBJECT

public:
    BlocklyNeutralRobotEditor(const QString &fileName);
    virtual ~BlocklyNeutralRobotEditor() override;

    virtual QString getPivot() override;
    virtual void save() override;

private slots:
    void loadProgram();

signals:
    void saveFinished();

private:
    QHBoxLayout layout;
    QWebEngineView view;

    QString pivotResult;

    QWebChannel channel;
    Channel* dataGetter;
};

// ################################################################################################

/**
 * @brief Class used to transfer information to the javascript via a QWebChannel
 */
class Channel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString content READ getFileContent)
public:
    Channel(const QString& content)
        : QObject(),
          fileContent(content)
    {
    }

public slots:
    QString getFileContent()
    {
        return fileContent;
    }

private:
    QString fileContent;
};

#endif // BLOCKLYNEUTRALROBOTEDITOR_H
