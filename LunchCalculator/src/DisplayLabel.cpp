#include "DisplayLabel.h"
#include <QskFontRole.h>
#include <QskSkin.h>
#include <QskSkinnable.h>
#include <QskTextLabel.h>
#include <qnamespace.h>
#include <QskBoxShapeMetrics.h>
#include <QskAspect.h>
#include <QskMargins.h>

QSK_SUBCONTROL(DisplayLabel, Panel)
QSK_SUBCONTROL(DisplayLabel, Text)

// DisplayLabel::DisplayLabel(const QString& text, QQuickItem* parent) : QskTextLabel(text, parent)
// {
//         //Subclass a control with local skin hints - maybe useful in the future?
//         setFontRole({QskFontRole::Display, QskFontRole::High});
//         setAlignment(Qt::AlignCenter);
//         setMargins(15);
//         setBackgroundColor(QColor("#004d40"));
//         setTextColor(QColor("#b2dfdb"));
//         setMetric(QskTextLabel::Panel | QskAspect::Border, 2);
//         setBoxShapeHint(QskTextLabel::Panel, 12);
// }

DisplayLabel::DisplayLabel(const QString& text, QQuickItem* parent) : QskTextLabel(text, parent)
{
        this->setPanel(QskTextLabel::Panel); // Allow painting of panel using skin factory
        // this->setMargins(QskMargins(8));
        setSubcontrolProxy(QskTextLabel::Panel, DisplayLabel::Panel);
        setSubcontrolProxy(QskTextLabel::Text, DisplayLabel::Text);
}