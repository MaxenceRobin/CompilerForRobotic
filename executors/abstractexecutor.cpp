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

void AbstractExecutor::showMessage(const QString &message, const QString &color)
{
    QPoint cursorPos = QCursor::pos();
    QRect tooltipArea(QPoint(cursorPos.x() - 100, cursorPos.y() - 100), QSize(200, 200));
    QToolTip::showText(cursorPos,
                       QString("<span style=\"color: %1;\">%2</span>")
                       .arg(color)
                       .arg(message),
                       nullptr,
                       tooltipArea);
}
