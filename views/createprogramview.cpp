#include "createprogramview.h"
#include "ui_createprogramview.h"

#include "models/projecttypelist.h"
#include "models/settings.h"

#include <QFileDialog>
#include <QDir>

#include <QDebug>

/**
 * @brief Construct a new dialog
 * @param parent : The hierarchical parent of the dialog
 */
CreateProgramView::CreateProgramView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateProgramView)
{
    ui->setupUi(this);

    // Settings
    fileNameValidator.setRegExp(QRegExp("[\\w\\-\\. ]+"));
    ui->programNameEdit->setValidator(&fileNameValidator);

    initProjectTypesList();

    // Connections
    connect(ui->browseLocationButton, &QPushButton::clicked, this, &CreateProgramView::browse);

    connect(ui->projectTypesList, &QListWidget::itemSelectionChanged, this, &CreateProgramView::updateAcceptability);
    connect(ui->programNameEdit, &QLineEdit::textChanged, this, &CreateProgramView::updateAcceptability);
    connect(ui->programLocationEdit, &QLineEdit::textChanged, this, &CreateProgramView::updateAcceptability);
}

/**
 * @brief Initializes the projec types list by retrieving information from the ProjectTypeList object
 */
void CreateProgramView::initProjectTypesList()
{
    const ProjectTypeList& typesList = ProjectTypeList::getSingleton();

    for (auto& type : typesList.getTypesList())
    {
        QListWidgetItem* item = new QListWidgetItem(QIcon(type->getIcon()), type->getName());
        ui->projectTypesList->addItem(item);
    }
}

/**
 * @brief Destructor of the dialog
 */
CreateProgramView::~CreateProgramView()
{
    delete ui;
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Resets the view so that it can be used again for a new program creation
 */
void CreateProgramView::resetView()
{
    ui->programNameEdit->clear();
    ui->programLocationEdit->setText(Settings::getDefaultProgramLocation());
    ui->defaultLocationCheckBox->setChecked(false);

    // Unselected all the project types
    for (int i = 0; i < ui->projectTypesList->count(); i++)
    {
        QListWidgetItem* item = ui->projectTypesList->item(i);
        ui->projectTypesList->setItemSelected(item, false);
    }
}

/**
 * @brief Dislpays the dialog and returns the name of the file to create, or an empty file name is the operation has been aborted
 * @return The name of the file to create or an empty string if the operation has been cancelled
 */
QString CreateProgramView::getProgramFileName()
{
    resetView();

    const ProjectTypeList& typesList = ProjectTypeList::getSingleton();

    if (exec() == CreateProgramView::Accepted)
    {
        if (ui->defaultLocationCheckBox->isChecked())
        {
            Settings::setDefaultProgramLocation(ui->programLocationEdit->text());
        }

        return ui->programLocationEdit->text() +
                "/" + ui->programNameEdit->text() +
                "." + typesList.getExtensionByName(ui->projectTypesList->selectedItems().first()->text());
    }
    else
    {
        return "";
    }
}

/**
 * @brief Opens a browsing dialog and update the file path in the line edit
 */
void CreateProgramView::browse()
{
    const QString fileDir = QFileDialog::getExistingDirectory(this, "Parcourir", Settings::getDefaultProgramLocation());

    // If the new location is invalid, the path is not replaced
    if (!fileDir.isEmpty())
    {
        ui->programLocationEdit->setText(fileDir);
    }
}

/**
 * @brief Updates the state of the "ok" button (enabled or disabled) depending on if all the required information are completed or not
 */
void CreateProgramView::updateAcceptability()
{
    bool enabled = true;

    // Valid program name
    if (ui->programNameEdit->text().isEmpty())
    {
        enabled = false;
    }

    // Valid program path
    QDir directory(ui->programLocationEdit->text());
    if (!directory.exists())
    {
        enabled = false;
    }

    // A project type must be selected
    if (ui->projectTypesList->selectedItems().isEmpty())
    {
        enabled = false;
    }

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(enabled);
}
