#ifndef BUTTONSGRIDBOX_H
#define BUTTONSGRIDBOX_H
#include <QskGridBox.h>
#include <QskAspect.h>
#include <QskSkinnable.h>
#include "DisplayLabel.h"

class ButtonsGridBox : public QskGridBox
{
    private:
        double m_firstOperand = 0;
        bool m_addMode = false;
        bool m_minusMode = false;
        bool m_multiplyMode = false;
        bool m_divideMode = false;
        bool m_operationPerformed = false;
    
    public:
        ButtonsGridBox(QQuickItem* parent, DisplayLabel* label);
        void setupFirstRowButtons(DisplayLabel* label);
        void setupSecondRowButtons(DisplayLabel* label);
        void setupThirdRowButtons(DisplayLabel* label);
        void setupFourthRowButtons(DisplayLabel* label);
        void setupFifthRowButtons(DisplayLabel* label);
};

#endif //BUTTONSGRIDBOX_H