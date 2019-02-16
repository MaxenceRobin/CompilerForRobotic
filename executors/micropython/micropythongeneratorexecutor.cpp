#include "micropythongeneratorexecutor.h"

#include "models/programfile.h"
#include <QFile>

#include <QApplication>
#include <QDebug>

#define GENERATION(name) QApplication::applicationDirPath() + "/Generation/" + name

/**
 * @brief Constructor of the executor
 */
MicroPythonGeneratorExecutor::MicroPythonGeneratorExecutor()
    : AbstractExecutor(),
      clipboard(QApplication::clipboard())
{
    hide();

    // Initialization of the debugging elements
    translateButton.setText("->");

    layout.addWidget(&inputCode);
    layout.addWidget(&translateButton);
    layout.addWidget(&outputCode);

    setLayout(&layout);

    // Loading of the pre program content
    //QFile preProgramContentFile(":/generators/micropython/preprogramcontent");
    QFile preProgramContentFile(GENERATION("preprogram.txt"));

    if (preProgramContentFile.open(QFile::Text | QFile::ReadOnly))
    {
        preProgramContent = preProgramContentFile.readAll();
        preProgramContentFile.close();
    }

    // Settings
    inputCode.setFont(QFont("Consolas", 14));
    inputCode.setTabStopDistance(30);
    outputCode.setFont(QFont("Consolas", 14));
    outputCode.setTabStopDistance(30);

    libFolder.setCurrent(GENERATION("lib"));

    // Connections
    connect(&translateButton, &QPushButton::clicked, this, &MicroPythonGeneratorExecutor::translateManualCode);
}

/**
 * @brief Destructor
 */
MicroPythonGeneratorExecutor::~MicroPythonGeneratorExecutor()
{
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Toggles the debug mode
 */
void MicroPythonGeneratorExecutor::toggleDebugMode()
{
    setVisible(isHidden());
}

/**
 * @brief Used in debug mode to translate and display a code written directly by the user
 */
void MicroPythonGeneratorExecutor::translateManualCode()
{
    execute(inputCode.toPlainText());
}

/**
 * @brief Translate the pivot code into MicroPython and set it into the clipboard to be pasted
 * @param pivot : The pivot code to work on
 */
void MicroPythonGeneratorExecutor::execute(const QString &pivot)
{
    inputCode.setText(pivot);

    QString result = QString::fromStdString(
                compiler.getMicroPythonFromPivot(pivot.toStdString())
                );

    clipboard->setText(result);
    outputCode.setText(result);

    // If there is no available port on the card, the whole operation is aborted
    QStringList availablePorts = sender.getPortNameList();
    if (availablePorts.isEmpty())
    {
        showMessage("Erreur : pas de carte trouvée", "red");
        return;
    }

    // Otherwise the first port is chosed
    sender.setPort(availablePorts.first());

    result = preProgramContent + "\n" + result;

    // Creation of the source file to be copied on the Wipy card
    ProgramFile sourceFile(GENERATION("main.py"));
    sourceFile.setContent(result);
    sourceFile.saveOnDisk();

    // The card is reseted to stop any running process
    showMessage("En attente que la carte soit prête à recevoir les données...", "purple");
    sender.reset();

    // Sending the program to the card
    showMessage("Début de l'envoi du programme", "blue");
    if (!sender.put(GENERATION("main.py"), "/flash/main.py"))
    {
        showMessage("Echec de l'envoi du programme", "red");
        return;
    }

    // If all the needed libraries were sent correctly
    if (sendLibraries())
    {
        showMessage("Envoi terminé", "green");
    }
    else
    {
    }
}

/**
 * @brief Sends the needed libraries on the card
 */
bool MicroPythonGeneratorExecutor::sendLibraries()
{
    // The list of the libraries already on the card is retrieved to be compared with the list of needed libraries
    const QStringList existingLibraries = sender.list("/flash/lib");
    const QStringList libList = libFolder.entryList(QDir::Files);

    // For each needed lib, if it is not already on the wipy card
    for (const auto& lib : libList)
    {
        if (!existingLibraries.contains(lib))
        {
            showMessage("Envoi de la bibliothèque " + lib, "blue");

            if (!sender.put(GENERATION("lib/" + lib), "/flash/lib"))
            {
                showMessage("Échec de l'envoi de la bibliothèque " + lib, "red");
                return false;
            }
        }
    }

    return true;
}
