#include "OtherButtons.h"
#include <QskAspect.h>
#include <QskPushButton.h>

QSK_SUBCONTROL(OtherButtons, Panel)
QSK_SUBCONTROL(OtherButtons, Text)

OtherButtons::OtherButtons(const QString& text, QQuickItem* parent) : QskPushButton(text, parent)
{
    setSubcontrolProxy(QskPushButton::Panel, Panel);
    setSubcontrolProxy(QskPushButton::Text, Text);
}