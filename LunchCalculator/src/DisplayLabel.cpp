#include "DisplayLabel.h"

DisplayLabel::DisplayLabel(const QString& text, QQuickItem* parent) : QskTextLabel(text, parent)
{
        setMargins(15);
        setBackgroundColor(Qt::cyan);
        setTextColor(Qt::darkMagenta);
}