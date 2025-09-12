#ifndef OTHERBUTTONS_H
#define OTHERBUTTONS_H
#include <QskAspect.h>
#include <QskPushButton.h>
#include <QskSkin.h>
#include <QskSkinnable.h>

class OtherButtons : public QskPushButton
{
    public:
        QSK_SUBCONTROLS(Panel, Text);

        OtherButtons(const QString& text, QQuickItem* parent = nullptr);
};

#endif //OTHERbUTTONS_H