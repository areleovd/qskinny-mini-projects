#include "OperationButtons.h"
#include <QskAspect.h>
#include <QskPushButton.h>
#include <QskSkin.h>
#include <QskSkinManager.h>

QSK_SUBCONTROL(OperationButtons, Panel)
QSK_SUBCONTROL(OperationButtons, Text)

OperationButtons::OperationButtons(const QString& text, QQuickItem* parent) : QskPushButton(text, parent)
{
    setSubcontrolProxy(QskPushButton::Panel, Panel);
    setSubcontrolProxy(QskPushButton::Text, Text);
}

