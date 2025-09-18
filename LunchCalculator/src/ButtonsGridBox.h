#ifndef BUTTONSGRIDBOX_H
#define BUTTONSGRIDBOX_H
#include <QskGridBox.h>
#include <QskAspect.h>
#include <QskSkinnable.h>
#include "DisplayLabel.h"

class ButtonsGridBox : public QskGridBox
{
    public:
        double firstOperand = 0;
        bool addMode = false;
        bool minusMode = false;
        bool multiplyMode = false;
        bool divideMode = false;
    
    public:
        ButtonsGridBox(QQuickItem* parent, DisplayLabel* label);
};

#endif //BUTTONSGRIDBOX_H