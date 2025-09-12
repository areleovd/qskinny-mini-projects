#include "NumberButtons.h"
#include <QskAspect.h>
#include <QskPushButton.h>
#include <QskSkinManager.h>


QSK_SUBCONTROL(NumberButtons, Panel)
QSK_SUBCONTROL(NumberButtons, Text)


NumberButtons::NumberButtons(const QString& text, QQuickItem* parent) : QskPushButton(text, parent)
{
    setSubcontrolProxy(QskPushButton::Panel, Panel);
    setSubcontrolProxy(QskPushButton::Text, Text);
}


