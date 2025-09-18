#ifndef DISPLAYLABEL_H
#define DISPLAYLABEL_H
#include <QskAspect.h>
#include <QskTextLabel.h>

class DisplayLabel : public QskTextLabel
{
        // Q_OBJECT
    public:
        QSK_SUBCONTROLS(Panel, Text)

        DisplayLabel(const QString& text, QQuickItem* parent = nullptr);
};



#endif