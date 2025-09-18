#include "ButtonsGridBox.h"

#include <QskGridBox.h>
#include <QskPushButton.h>
#include <QskTextLabel.h>

#include "DisplayLabel.h"
#include "NumberButtons.h"
#include "OperationButtons.h"
#include "OtherButtons.h"

ButtonsGridBox::ButtonsGridBox(QQuickItem* parent, DisplayLabel* label) : QskGridBox(parent)
{

    // auto* this = new QskGridBox(parent);
    this->setPanel(true);
    this->setSpacing(5);
    for (int  i = 0; i <=3 ; i++)
    {
        this->addColumnSpacer(50, i);
    }

    //First row
    auto* otherACButton = new OtherButtons("AC");
    auto* otherBraceButton = new OtherButtons("()"); //Not use for now
    auto* otherPercentButton = new OtherButtons("%");
    auto* operationDivideButton = new OperationButtons("/");

    this->addItem(otherACButton, 0,0, 1,2);
    // this->addItem(otherBraceButton, 0,1); //wiill be uncommented once we figured out how to consider braces in the calculation
    this->addItem(otherPercentButton, 0,2);
    this->addItem(operationDivideButton, 0,3);
    
    QStringList firstRowText = {otherACButton->text(), otherBraceButton->text(), otherPercentButton->text(), operationDivideButton->text()};
    for (auto &frText : firstRowText)
    {
        if (frText == "AC")
        {
            QObject::connect(otherACButton, &QskPushButton::clicked, [label, this]()
            {
                label->setText("0");
                firstOperand = 0;
                addMode = false;
                minusMode = false;
                multiplyMode = false;
                divideMode = false;
                        
            });
        }
        else if (frText == "()")
        {
            QObject::connect(otherBraceButton, &QskPushButton::clicked, [label, this]()
            {
                //TODO: Improve the usage of (). Consider the operator priority when () is used
                QString current = label->text();
                if (current == "0")
                {
                    label->setText("(");
                    // braceCount = 1;
                }
                else if ((current != "0") &&  (current.contains("(") == 0))
                {
                    label->setText("(" + current);
                    // braceCount = 1;
                }
                else 
                {
                    label->setText(current + ")");
                    // braceCount = 0;
                }
                 
            });
        }
        else if (frText == "%")
        {
            QObject::connect(otherPercentButton, &QskPushButton::clicked, [label, this]()
            {
                firstOperand = (label->text().toDouble())/100;
            });
        }
        else if (frText == "/")
        {
            QObject::connect(operationDivideButton, &QskPushButton::clicked,  [label, this]()
            {
                firstOperand = label->text().toDouble();
                label->setText("0");
                divideMode = true;
            });
        }
    }


    //Second row
    auto* numberSevenButton = new NumberButtons("7");
    auto* numberEightButton = new NumberButtons("8");
    auto* numberNineButton = new NumberButtons("9");
    auto* operationMultiplyButton = new OperationButtons("X");
    
    this->addItem(numberSevenButton, 1,0);
    this->addItem(numberEightButton, 1,1);
    this->addItem(numberNineButton, 1,2);
    this->addItem(operationMultiplyButton, 1, 3);

    QStringList secondRowText = {numberSevenButton->text(), numberEightButton->text(), numberNineButton->text(), operationMultiplyButton->text()};
    for (auto &srText : secondRowText)
    {
        if (srText == "7")
        {
            QObject::connect(numberSevenButton, &QskPushButton::clicked, [label, numberSevenButton]()
            { 
                QString current = label->text();
                if (current == "0")
                    label->setText(numberSevenButton->text());
                else
                    label->setText(current + numberSevenButton->text());
            
            });
        }
        else  if (srText == "8")
        {
            QObject::connect(numberEightButton, &QskPushButton::clicked, [label, numberEightButton]()
            { 
                QString current = label->text();
                if (current == "0")
                    label->setText(numberEightButton->text());
                else
                    label->setText(current + numberEightButton->text());
            
            });
        }
        else  if (srText == "9")
        {
            QObject::connect(numberNineButton, &QskPushButton::clicked, [label, numberNineButton]()
            { 
                QString current = label->text();
                if (current == "0")
                    label->setText(numberNineButton->text());
                else
                    label->setText(current + numberNineButton->text());
            
            });
        }
        else if (srText == "X")
        {
            QObject::connect(operationMultiplyButton, &QskPushButton::clicked,  [label, this]()
            {
                firstOperand = label->text().toDouble();
                label->setText("0");
                multiplyMode = true;
            });
        }

    }

    //Third row
    auto* numberFourButton = new NumberButtons("4");
    auto* numberFiveButton = new NumberButtons("5");
    auto* numberSixButton = new NumberButtons("6");
    auto* operationMinusButton = new OperationButtons("-");

    this->addItem(numberFourButton, 2,0);
    this->addItem(numberFiveButton, 2, 1);
    this->addItem(numberSixButton, 2, 2);
    this->addItem(operationMinusButton, 2,3);

    QStringList thirdRowText = {numberFourButton->text(), numberFiveButton->text(), numberSixButton->text(), operationMinusButton->text()};
    for (auto &trText : thirdRowText)
    {
        if (trText == "4")
        {
            QObject::connect(numberFourButton, &QskPushButton::clicked, [label, numberFourButton]()
            { 
                QString current = label->text();
                if (current == "0")
                    label->setText(numberFourButton->text());
                else
                    label->setText(current + numberFourButton->text());
            
            });
        }
        else  if (trText == "5")
        {
            QObject::connect(numberFiveButton, &QskPushButton::clicked, [label, numberFiveButton]()
            { 
                QString current = label->text();
                if (current == "0")
                    label->setText(numberFiveButton->text());
                else
                    label->setText(current + numberFiveButton->text());
            
            });
        }
        else  if (trText == "6")
        {
            QObject::connect(numberSixButton, &QskPushButton::clicked, [label, numberSixButton]()
            { 
                QString current = label->text();
                if (current == "0")
                    label->setText(numberSixButton->text());
                else
                    label->setText(current + numberSixButton->text());
            
            });
        }
        else  if (trText == "-")
        {
            QObject::connect(operationMinusButton, &QskPushButton::clicked,  [label, this]()
            {
                firstOperand = label->text().toDouble();
                label->setText("0");
                minusMode = true;
            });
        }        
    }

    //Fourth row
    auto* numberOneButton = new NumberButtons("1");
    auto* numberTwoButton = new NumberButtons("2");
    auto* numberThreeButton = new NumberButtons("3");
    auto* operationPlusButton = new OperationButtons("+");

    this->addItem(numberOneButton, 3, 0);
    this->addItem(numberTwoButton, 3,1);
    this->addItem(numberThreeButton, 3,2);
    this->addItem(operationPlusButton, 3,3);

    QStringList fourthRowText = {numberOneButton->text(), numberTwoButton->text(), numberThreeButton->text(), operationPlusButton->text()};
    for (auto &fourText : fourthRowText)
    {
        if (fourText == "1")
        {
            QObject::connect(numberOneButton, &QskPushButton::clicked, [label, numberOneButton]()
            { 
                QString current = label->text();
                if (current == "0")
                    label->setText(numberOneButton->text());
                else
                    label->setText(current + numberOneButton->text());
            
            });
        }
        else  if (fourText == "2")
        {
            QObject::connect(numberTwoButton, &QskPushButton::clicked, [label, numberTwoButton]()
            { 
                QString current = label->text();
                if (current == "0")
                    label->setText(numberTwoButton->text());
                else
                    label->setText(current + numberTwoButton->text());
            
            });
        }
        else  if (fourText == "3")
        {
            QObject::connect(numberThreeButton, &QskPushButton::clicked, [label, numberThreeButton]()
            { 
                QString current = label->text();
                if (current == "0")
                    label->setText(numberThreeButton->text());
                else
                    label->setText(current + numberThreeButton->text());
            
            });
        }
        else  if (fourText == "+")
        {
            QObject::connect(operationPlusButton, &QskPushButton::clicked,  [label, this]()
            {
                firstOperand = label->text().toDouble();
                label->setText("0");
                addMode = true;
            });
        }        
    }    

    //Fifth row
    auto* otherPosNegButton = new OtherButtons("+/-");
    auto* numberZeroButton = new NumberButtons("0");
    auto* otherDecimalButton = new OtherButtons(".");
    auto* operationEqualButton = new OperationButtons("=");

    this->addItem(otherPosNegButton, 4, 0);
    this->addItem(numberZeroButton, 4,1);
    this->addItem(otherDecimalButton, 4, 2);
    this->addItem(operationEqualButton, 4, 3);

    QStringList fifthRowText = {otherPosNegButton->text(), numberZeroButton->text(), otherDecimalButton->text(), operationEqualButton->text()};
    for (auto &fifthText : fifthRowText)
    {
        if (fifthText == "+/-")
        {
            QObject::connect(otherPosNegButton, &QskPushButton::clicked, [label, this]()
            {
                QString current = label->text();
                if (current == "0")
                {
                    //Do nothing I guess?
                }
                else
                {
                    double currentState  = current.toDouble();
                    firstOperand = currentState  *  (-1);
                    label->setText(QString::number(firstOperand));

                }

            });
        }
        else  if (fifthText == "0")
        {
            QObject::connect(numberZeroButton, &QskPushButton::clicked, [label, numberZeroButton]()
            { 
                QString current = label->text();
                if (current == "0")
                    label->setText(numberZeroButton->text());
                else
                    label->setText(current + numberZeroButton->text());
            
            });
        }
        else  if (fifthText == ".")
        {
            QObject::connect(otherDecimalButton,&QskPushButton::clicked, [label, this]()
            {
                QString current = label->text();
                if  (current == "0" && current.contains(".") == 0)
                {
                    label->setText(current + ".");
                }
                else if (current != "0" && current.contains(".") == 0)
                {
                    label->setText(current + ".");
                }
                else if (current.contains(".") == 1)
                {
                    
                }

            });
        }
        else  if (fifthText == "=")
        {
            QObject::connect(operationEqualButton, &QskPushButton::clicked, [label, this]()
            {
                double secondOperand = label->text().toDouble();
                double result = 0;
                if (addMode)
                { 
                    result = firstOperand + secondOperand;
                    addMode = false;

                }
                else if (minusMode)
                {
                    result = firstOperand - secondOperand;
                    minusMode = false;
                }
                else if (divideMode)
                {
                    //TODO: error handling when division by 0
                    result = firstOperand / secondOperand;
                    divideMode = false;
                }
                else if (multiplyMode)
                {
                    result = firstOperand * secondOperand;
                    multiplyMode = false;
                }
                else 
                {
                    result = firstOperand;
                }
                label->setText(QString::number(result));
                firstOperand = 0;

            });
        }        
    } 
}