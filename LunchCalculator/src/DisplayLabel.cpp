#include "DisplayLabel.h"
#include <QskFontRole.h>
#include <QskSkin.h>
#include <qnamespace.h>

DisplayLabel::DisplayLabel(const QString& text, QQuickItem* parent) : QskTextLabel(text, parent)
{
        setFontRole({QskFontRole::Display, QskFontRole::High});
        setAlignment(Qt::AlignCenter);
        setMargins(15);
        setBackgroundColor(QColor("#004d40"));
        setTextColor(QColor("#b2dfdb"));
}