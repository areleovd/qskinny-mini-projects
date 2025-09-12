#ifndef OPERATIONBUTTONS_H
#define OPERATIONBUTTONS_H
#include <QskAspect.h>
#include <QskPushButton.h>
#include <QskSkinnable.h>

class OperationButtons : public QskPushButton
{
    public:
        QSK_SUBCONTROLS(Panel, Text)

        OperationButtons(const QString& text, QQuickItem* parent = nullptr );

};

#endif