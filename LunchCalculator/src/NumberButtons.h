#ifndef NUMBERBUTTONS_H
#define NUMBERBUTTONS_H
#include <QskAspect.h>
#include <QskPushButton.h>
#include <QskSkinnable.h>

    
class NumberButtons : public QskPushButton
{
//   Q_OBJECT      
    public:
        QSK_SUBCONTROLS(Panel, Text)

        NumberButtons(const QString& text, QQuickItem* parent = nullptr );    
};


#endif