#ifndef ABSTRACTBLOCKLYEDITOR_H
#define ABSTRACTBLOCKLYEDITOR_H

#include "abstracteditor.h"

#include <QWebEngineView>
#include <QHBoxLayout>
#include <QString>
#include <QWebChannel>
#include <QEventLoop>

#include <QDebug>

/**
 * @brief A base class for all the editor using BLockly
 */
class BaseBlocklyEditor : public AbstractEditor
{
    Q_OBJECT
    Q_PROPERTY(QString content READ getFileContent)

    // Protected constructor to avoid instanciations even though the class is not abstract
protected:
    BaseBlocklyEditor(const QString &fileName, const QString& blocklyFile);

public:
    virtual ~BaseBlocklyEditor() override;

    virtual QString getPivot() override;
    virtual void save() override;

    QString getFileContent();

private slots:
    void loadProgram();

    virtual void toggleDebugMode() override;

signals:
    void endLoop();

private:
    QHBoxLayout layout;
    QWebEngineView view;

    QString pivotResult;

    QWebChannel channel;

    QEventLoop blockingLoop;
};
#endif // ABSTRACTBLOCKLYEDITOR_H
