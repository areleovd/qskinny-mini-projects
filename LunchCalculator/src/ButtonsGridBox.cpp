#include "ButtonsGridBox.h"

#include <QskGridBox.h>
#include <QskPushButton.h>
#include <QskTextLabel.h>
#include <qguiapplication_platform.h>

#include "DisplayLabel.h"
#include "NumberButtons.h"
#include "OperationButtons.h"
#include "OtherButtons.h"

ButtonsGridBox::ButtonsGridBox(QQuickItem* parent, DisplayLabel* label) : QskGridBox(parent)
{

    this->setPanel(true);
    this->setSpacing(5);
    for (int  i = 0; i <=3 ; i++)
    {
        this->addColumnSpacer(50, i);
    }

    setupFirstRowButtons(label);
    setupSecondRowButtons(label);
    setupThirdRowButtons(label);
    setupFourthRowButtons(label);
    setupFifthRowButtons(label);
}

void ButtonsGridBox::setupFirstRowButtons(DisplayLabel* label)
{
        //First row;
    QStringList firstRowText = {"AC", "()", "%", "/"};
    for (auto &frText : firstRowText)
    {
        if (frText != "/")
        {
            auto *otherButton = new OtherButtons(frText);
            if (otherButton->text() == "AC")
            {
                this->addItem(otherButton, 0,0, 1,2);
                QObject::connect(otherButton, &QskPushButton::clicked, [label, this]()
                {
                    label->setText("0");
                    m_firstOperand = 0;
                    m_addMode = false;
                    m_minusMode = false;
                    m_multiplyMode = false;
                    m_divideMode = false;
                    m_operationPerformed = false;
                            
                });
            }
            else if (otherButton->text() == "()")
            {
                // this->addItem(otherButton, 0,1); //wiill be uncommented once we figured out how to consider braces in the calculation
                QObject::connect(otherButton, &QskPushButton::clicked, [label, this]()
                {
                    //TODO: Improve the usage of (). Consider the operator priority when () is used
                    QString current = label->text();
                    if (current == "0")
                    {
                        label->setText("(");
                    }
                    else if ((current != "0") &&  (current.contains("(") == 0))
                    {
                        label->setText("(" + current);
                    }
                    else 
                    {
                        label->setText(current + ")");
                    }
                    
                });
            }
            else
            {
                this->addItem(otherButton, 0,2);
                QObject::connect(otherButton, &QskPushButton::clicked, [label, this]()
                {
                    QString current = label->text();
                    if (current != "0")
                    {
                        m_firstOperand = (current.toDouble())/100;
                        label->setText(QString::number(m_firstOperand));
                    }
                });             
            }
        }
        else 
        {
            auto *operationButton = new OperationButtons(frText);
            this->addItem(operationButton,0,3);
            QObject::connect(operationButton, &QskPushButton::clicked,  [label, this]()
            {
                m_firstOperand = label->text().toDouble();
                label->setText("0");
                m_divideMode = true;
            });
        }
    }
}

void ButtonsGridBox::setupSecondRowButtons(DisplayLabel* label)
{
   //Second row
    QStringList secondRowText = {"7", "8", "9", "X"};
    for (auto &srText : secondRowText)
    {
            if (srText != "X")
            {
                auto* srNumberButton = new NumberButtons(srText);
                if (srText == "7")
                    this->addItem(srNumberButton, 1, 0);
                else if (srText == "8")
                    this->addItem(srNumberButton, 1, 1);
                else
                    this->addItem(srNumberButton, 1, 2);
                QObject::connect(srNumberButton, &QskPushButton::clicked, [label, srNumberButton, this]()
                { 
                    QString current = label->text();
                    if (current == "0")
                    {
                        label->setText(srNumberButton->text());
                    }
                    else if (current != "0" && m_operationPerformed == true)
                    {
                        label->setText(srNumberButton->text());
                        m_operationPerformed = false;
                    }
                    else
                    {
                        label->setText(current + srNumberButton->text());
                    }
                });
            }
            else 
            {
                auto *operationButton = new OperationButtons (srText);
                this->addItem(operationButton, 1, 3);
                QObject::connect(operationButton, &QskPushButton::clicked,  [label, this]()
                {
                    m_firstOperand = label->text().toDouble();
                    label->setText("0");
                    m_multiplyMode = true;
                });
            }
    }
}

void ButtonsGridBox::setupThirdRowButtons(DisplayLabel* label)
{
    //Third row
    QStringList thirdRowText = {"4", "5", "6", "-"};
    for (auto &trText : thirdRowText)
    {
        if (trText != "-")
        {
            auto* trNumberButton = new NumberButtons(trText);
            if (trText == "4")
                this->addItem(trNumberButton, 2, 0);
            else if (trText == "5")
                this->addItem(trNumberButton, 2, 1);
            else
                this->addItem(trNumberButton, 2, 2);
            QObject::connect(trNumberButton, &QskPushButton::clicked, [label, trNumberButton, this]()
            { 
                QString current = label->text();
                if (current == "0")
                {
                    label->setText(trNumberButton->text());
                }
                else if (current != "0" && m_operationPerformed == true)
                {
                    label->setText(trNumberButton->text());
                    m_operationPerformed = false;
                }
                else
                {
                    label->setText(current + trNumberButton->text());
                }
            });
        }
        else 
        {
            auto *operationButton = new OperationButtons (trText);
            this->addItem(operationButton, 2, 3);
            QObject::connect(operationButton, &QskPushButton::clicked,  [label, this]()
            {
                m_firstOperand = label->text().toDouble();
                label->setText("0");
                m_minusMode = true;
            });
        }
             
    }    
}

void ButtonsGridBox::setupFourthRowButtons(DisplayLabel* label)
{
    //Fourth row
    QStringList fourthRowText = {"1", "2", "3", "+"};
    for (auto &fourText : fourthRowText)
    {
        
        if (fourText != "+")
        {
            auto* fourthRowNumberButton = new NumberButtons(fourText);
            if (fourText == "1")
                this->addItem(fourthRowNumberButton, 3, 0);
            else if (fourText == "2")
                this->addItem(fourthRowNumberButton, 3, 1);
            else
                this->addItem(fourthRowNumberButton, 3, 2);
            QObject::connect(fourthRowNumberButton, &QskPushButton::clicked, [label, fourthRowNumberButton, this]()
            { 
                QString current = label->text();
                if (current == "0")
                {
                    label->setText(fourthRowNumberButton->text());
                }
                else if (current != "0" && m_operationPerformed == true)
                {
                    label->setText(fourthRowNumberButton->text());
                    m_operationPerformed = false;
                }
                else
                {
                    label->setText(current + fourthRowNumberButton->text());
                }
            });
        }
        else 
        {
            auto *operationButton = new OperationButtons (fourText);
            this->addItem(operationButton, 3, 3);
            QObject::connect(operationButton, &QskPushButton::clicked,  [label, this]()
            {
                m_firstOperand = label->text().toDouble();
                label->setText("0");
                m_addMode = true;
            });
        }
               
    }       
}

void ButtonsGridBox::setupFifthRowButtons(DisplayLabel* label)
{
    //Fifth row
    QStringList fifthRowText = {"+/-", "0", ".", "="};
    for (auto &fifthText : fifthRowText)
    {
        if (fifthText == "0")
        {
            auto* fifthRowNumberButton = new NumberButtons(fifthText);
            this->addItem(fifthRowNumberButton, 4, 1);
            QObject::connect(fifthRowNumberButton, &QskPushButton::clicked, [label, fifthRowNumberButton, this]()
            { 
                QString current = label->text();
                if (current == "0")
                {
                    label->setText(fifthRowNumberButton->text());
                }
                else if (current != "0" && m_operationPerformed == true)
                {
                    label->setText(fifthRowNumberButton->text());
                    m_operationPerformed = false;
                }
                else
                {
                    label->setText(current + fifthRowNumberButton->text());
                }
            });
        }
        else if (fifthText == "=")
        {
            auto *operationButton = new OperationButtons(fifthText);
            this->addItem(operationButton, 4,3);
            QObject::connect(operationButton, &QskPushButton::clicked, [label, this]()
            {
                double secondOperand = label->text().toDouble();
                double result = 0;
                if (m_addMode)
                { 
                    result = m_firstOperand + secondOperand;
                    m_addMode = false;

                }
                else if (m_minusMode)
                {
                    result = m_firstOperand - secondOperand;
                    m_minusMode = false;
                }
                else if (m_divideMode)
                {
                    //TODO: error handling when division by 0
                    result = m_firstOperand / secondOperand;
                    m_divideMode = false;
                }
                else if (m_multiplyMode)
                {
                    result = m_firstOperand * secondOperand;
                    m_multiplyMode = false;
                }
                label->setText(QString::number(result));
                m_firstOperand = 0;
                m_operationPerformed = true;

            });         
        }
        else 
        {
            auto* otherButton = new OtherButtons(fifthText);
            if (otherButton->text() == "+/-")
            {
                this->addItem(otherButton, 4, 0);
                QObject::connect(otherButton, &QskPushButton::clicked, [label, this]()
                {
                    QString current = label->text();
                    if (current != "0")
                    {
                        double currentState  = current.toDouble();
                        m_firstOperand = currentState  *  (-1);
                        label->setText(QString::number(m_firstOperand));
                    }
                });

            }
            else 
            {
                this->addItem(otherButton, 4, 2);
                QObject::connect(otherButton,&QskPushButton::clicked, [label, this]()
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

                });                
            }
        }
              
    } 
}    
