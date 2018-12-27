#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>

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

signals:
    void closeRequested();

    // Special access for the controller
protected:
    QTextEdit& getCodeInput();
    QTextEdit& getCodeOutput();
    QPushButton& getTranslateButton();
    QAction& getQuitAction();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
