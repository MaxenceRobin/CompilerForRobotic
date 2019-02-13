#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "editors/abstracteditor.h"
#include "executors/abstractexecutor.h"

#include "createprogramview.h"

#include "models/programfile.h"

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

private:
    void closeEvent(QCloseEvent* event);

    void loadEnvironment(AbstractEditor* newEditor, AbstractExecutor* newExecutor);
    void removeEnvironment();

    void processBeforeQuitting();
    void loadProgram(const QString& fileName);

private:
    void replaceEnvironment(QWidget* newEditor, QWidget* newExecutor);
    void setProjectMode(bool mode);

private slots:
    void createProgram();
    void openProgram();
    void closeProgram();
    void saveProgram();
    void sendProgram();

private:
    Ui::MainWindow *ui;

    QWidget* editor;
    QWidget* executor;

    bool projectOpen;

    CreateProgramView createProgramDialog;
};

#endif // MAINWINDOW_H
