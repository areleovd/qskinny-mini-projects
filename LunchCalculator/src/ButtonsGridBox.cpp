#include "ButtonsGridBox.h"

#include <QskGridBox.h>
#include <QskTextLabel.h>

#include "DisplayLabel.h"
#include "NumberButtons.h"
#include "OperationButtons.h"
#include "OtherButtons.h"

ButtonsGridBox::ButtonsGridBox(QQuickItem* parent, DisplayLabel* label) : QskGridBox(parent)
{

    auto* buttonsBox = new QskGridBox(parent);
    buttonsBox->setPanel(true);
    buttonsBox->setSpacing(10);

    //First row
    auto* otherACButton = new OtherButtons("AC");
    auto* otherBraceButton = new OtherButtons("()");
    auto* otherPercentButton = new OtherButtons("%");
    auto* operationDivideButton = new OperationButtons("/");

    buttonsBox->addItem(otherACButton, 0,0);
    buttonsBox->addItem(otherBraceButton, 0,1);
    buttonsBox->addItem(otherPercentButton, 0,2);
    buttonsBox->addItem(operationDivideButton, 0,3);
    
    //Second row
    auto* numberSevenButton = new NumberButtons("7");
    auto* numberEightButton = new NumberButtons("8");
    auto* numberNineButton = new NumberButtons("9");
    auto* operationMultiplyButton = new OperationButtons("X");
    
    buttonsBox->addItem(numberSevenButton, 1,0);
    buttonsBox->addItem(numberEightButton, 1,1);
    buttonsBox->addItem(numberNineButton, 1,2);
    buttonsBox->addItem(operationMultiplyButton, 1, 3);

    QObject::connect(numberSevenButton, &QskPushButton::clicked, [label, numberSevenButton]()
    { 
        QString current = label->text();
        if (current == "0")
            label->setText(numberSevenButton->text());
        else
            label->setText(current + numberSevenButton->text());
    
    });

    //Third row
    auto* numberFourButton = new NumberButtons("4");
    auto* numberFiveButton = new NumberButtons("5");
    auto* numberSixButton = new NumberButtons("6");
    auto* operationMinusButton = new OperationButtons("-");

    buttonsBox->addItem(numberFourButton, 2,0);
    buttonsBox->addItem(numberFiveButton, 2, 1);
    buttonsBox->addItem(numberSixButton, 2, 2);
    buttonsBox->addItem(operationMinusButton, 2,3);

    //Fourth row
    auto* numberOneButton = new NumberButtons("1");
    auto* nummberTwoButton = new NumberButtons("2");
    auto* numberThreeButton = new NumberButtons("3");
    auto* operationPlusButton = new OperationButtons("+");

    buttonsBox->addItem(numberOneButton, 3, 0);
    buttonsBox->addItem(nummberTwoButton, 3,1);
    buttonsBox->addItem(numberThreeButton, 3,2);
    buttonsBox->addItem(operationPlusButton, 3,3);

    //Fifth row
    auto* otherPosNegButton = new OtherButtons("+/-");
    auto* numberZeroButton = new NumberButtons("0");
    auto* otherDecimalButton = new OtherButtons(".");
    auto* operationEqualButton = new OperationButtons("=");

    buttonsBox->addItem(otherPosNegButton, 4, 0);
    buttonsBox->addItem(numberZeroButton, 4,1);
    buttonsBox->addItem(otherDecimalButton, 4, 2);
    buttonsBox->addItem(operationEqualButton, 4, 3);

}