#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "editors/abstracteditor.h"
#include "executors/abstractexecutor.h"

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QWebEngineView>

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class
 * This class is the main view of the application. It contains all the GUI
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void closeEvent(QCloseEvent* event);
    void setEnvironment(AbstractEditor* newEditor, AbstractExecutor* newExecutor);

signals:
    void closeRequested();

    // Special access for the controller
protected:
    QAction& getQuitAction();
    QAction& getSendAction();

private:
    Ui::MainWindow *ui;

    QWidget* editor;
    QWidget* executor;
};

#endif // MAINWINDOW_H
