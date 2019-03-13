#include "micropythongeneratorexecutor.h"

#include "models/programfile.h"
#include <QFile>

#include <QApplication>
#include <QDebug>

#define GENERATION(name) QApplication::applicationDirPath() + "/Ressources/Generation/" + name
#define AMPY(name) QApplication::applicationDirPath() + "/Ressources/Ampy/" + name

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
    saveButton.setText("Save");

    layout.addWidget(&inputCode);
    layout.addWidget(&translateButton);
    layout.addWidget(&saveButton);
    layout.addWidget(&outputCode);

    setLayout(&layout);

    // Creation of the associated actions
    startProgramAction.setIcon(QIcon(":/icons/startprogram"));
    startProgramAction.setToolTip("Démarrer le programme");

    stopProgramAction.setIcon(QIcon(":/icons/stopprogram"));
    stopProgramAction.setToolTip("Arrêter le programme");

    actionsList << &startProgramAction
                << &stopProgramAction;

    // Loading of the pre and post program content
    QFile preProgramContentFile(GENERATION("preprogram.txt"));

    if (preProgramContentFile.open(QFile::Text | QFile::ReadOnly))
    {
        preProgramContent = preProgramContentFile.readAll();
        preProgramContentFile.close();
    }

    QFile postProgramContentFile(GENERATION("postprogram.txt"));

    if (postProgramContentFile.open(QFile::Text | QFile::ReadOnly))
    {
        postProgramContent = postProgramContentFile.readAll();
        postProgramContentFile.close();
    }

    // Settings
    inputCode.setFont(QFont("Consolas", 14));
    inputCode.setTabStopDistance(30);
    outputCode.setFont(QFont("Consolas", 14));
    outputCode.setTabStopDistance(30);

    libFolder.setCurrent(GENERATION("lib"));

    // Connections
    connect(&translateButton, &QPushButton::clicked, this, &MicroPythonGeneratorExecutor::translateManualCode);
    connect(&saveButton, &QPushButton::clicked, this, &MicroPythonGeneratorExecutor::saveCode);

    connect(&startProgramAction, &QAction::triggered, this, &MicroPythonGeneratorExecutor::startProgram);
    connect(&stopProgramAction, &QAction::triggered, this, &MicroPythonGeneratorExecutor::stopProgram);
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
 * @brief Initializes the wipy card by finding an appropriate port
 * @return 'true' is the operation was successful, 'false' otherwise
 */
bool MicroPythonGeneratorExecutor::initSenderPort()
{
    // If there is no available port on the card, the whole operation is aborted
    QStringList availablePorts = sender.getPortNameList();
    if (availablePorts.isEmpty())
    {
        return false;
    }

    // Otherwise the first port is chosed
    sender.setPort(availablePorts.first());

    return true;
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

    if (!initSenderPort())
    {
        showMessage("Erreur : pas de carte trouvée", "red");
        return;
    }

    result = preProgramContent + "\n" + result + "\n" + postProgramContent;

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
        sender.stop();
        return;
    }
    else
    {
        // If all the needed libraries were sent correctly
        if (sendLibraries())
        {
            showMessage("Envoi terminé", "green");
        }
    }
}

/**
 * @brief Returns the icon that will represent the execute action in the main window
 * @return The icon that will represent the execute action in the main window
 */
const QIcon MicroPythonGeneratorExecutor::getIcon()
{
    return QIcon(":/icons/upload");
}

/**
 * @brief Returns the tool tip that will describe the execute action in the main window
 * @return The tool tip that will describe the execute action in the main window
 */
const QString MicroPythonGeneratorExecutor::getToolTip()
{
    return "Envoyer le programme vers le robot";
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

/**
 * @brief Starts the program on the robot
 */
void MicroPythonGeneratorExecutor::startProgram()
{
    if (!initSenderPort())
    {
        showMessage("Erreur : pas de carte trouvée", "red");
    }
    else
    {
        showMessage("Démarrarge du programme", "blue");

        //if (sender.execute("python", QStringList() << AMPY("startprogram.py") << sender.getPortName()))
        if (sender.execute(QString("python %1 %2")
                           .arg(AMPY("startprogram.py"))
                           .arg(sender.getPortName())))
        {
            showMessage("Programme démarré", "green");
        }
        else
        {
            showMessage("Echec du démarrage du programme", "red");
        }
    }
}

/**
 * @brief Stops any started program
 */
void MicroPythonGeneratorExecutor::stopProgram()
{
    if (!initSenderPort())
    {
        showMessage("Erreur : pas de carte trouvée", "red");
    }
    else
    {
        showMessage("Arrêt du programme", "red");
        sender.reset();
        showMessage("Programme arrêté", "green");
    }
}

/**
 * @brief Saves on the disk as save.py the program currently installed on the wipy card on /flash/main.py
 */
void MicroPythonGeneratorExecutor::saveCode()
{
    showMessage("Sauvegarde du programme...", "blue");

    if (!initSenderPort())
    {
        showMessage("Erreur : pas de carte trouvée", "red");
        return;
    }

    sender.reset();

    const QString& code = sender.get("/flash/main.py");

    ProgramFile codeFile(GENERATION("save.py"));
    codeFile.setContent(code);
    codeFile.saveOnDisk();

    showMessage("Sauvegarde réussie", "green");
}
