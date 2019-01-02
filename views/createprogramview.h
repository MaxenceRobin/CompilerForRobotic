#ifndef CREATEPROGRAMVIEW_H
#define CREATEPROGRAMVIEW_H

#include <QDialog>
#include <QString>
#include <QRegExpValidator>

namespace Ui {
class CreateProgramView;
}

/**
 * @brief This class represents a dialog window to create a new program
 */
class CreateProgramView : public QDialog
{
    Q_OBJECT

public:
    explicit CreateProgramView(QWidget *parent = nullptr);
    ~CreateProgramView();

    QString getProgramFileName();

private:
    void initProjectTypesList();
    void resetView();

public slots:
    void browse();

private slots:
    void updateAcceptability();

private:
    Ui::CreateProgramView *ui;
    QRegExpValidator fileNameValidator;
};

#endif // CREATEPROGRAMVIEW_H
