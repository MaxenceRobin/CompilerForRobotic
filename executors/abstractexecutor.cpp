#include "abstractexecutor.h"

#include <QToolTip>
#include <QCursor>

/**
 * @brief Constructor of the executor
 */
AbstractExecutor::AbstractExecutor()
    : QWidget()
{
}

/**
 * @brief Destructor of the executor
 */
AbstractExecutor::~AbstractExecutor()
{
    // Nothing to destroy
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Returns the list of associated actions of the executor
 * @return The list of the associated actions of the executor
 */
const QList<QAction*>& AbstractExecutor::getActions()
{
    return actionsList;
}

/**
 * @brief Shows a tooltip at the cursor position
 * @param message : The message to show
 * @param color : The color of the font, in CSS syntax
 * @param size : The size of the font, in CSS syntax
 */
void AbstractExecutor::showMessage(const QString &message, const QString &color, const QString &size)
{
    QPoint cursorPos = QCursor::pos();
    QRect tooltipArea(QPoint(cursorPos.x() - 200, cursorPos.y() - 200), QSize(200, 200));
    QToolTip::showText(cursorPos,
                       QString("<span style=\"color: %1; font-size: %2;\">%3</span>")
                       .arg(color)
                       .arg(size)
                       .arg(message),
                       this,
                       tooltipArea);
}
