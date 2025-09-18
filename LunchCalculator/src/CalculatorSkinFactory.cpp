#include "CalculatorSkinFactory.h"
#include <QskAspect.h>
#include <QskPushButton.h>
#include <QskSkin.h>
#include <QskSkinnable.h>
#include <QskSkinHintTableEditor.h>
#include <QskTextLabel.h>
#include <qnamespace.h>
#include "NumberButtons.h"
#include "OperationButtons.h"
#include "OtherButtons.h"
#include <QskFontRole.h>
#include "DisplayLabel.h"

CalculatorSkinFactory::CalculatorSkinFactory(QObject* parent) : QskSkinFactory(parent)
{

}

QStringList CalculatorSkinFactory::skinNames() const
{
        return{"PastelSkin"};
}

QskSkin* CalculatorSkinFactory::createSkin(const QString& skinName) 
{
    if(skinName == "PastelSkin")
    {
        class PastelSkin : public QskSkin
        {
            
            protected:
                void initHints() override
                {
                    auto* myMargin = new QskMargins;
                    QskSkinHintTableEditor e(&hintTable());
                    {
                        //This sets the whole system font to the following settings
                        setFont(QskFontRole::Body, QFont("Calibri", 14, QFont::Bold));

                        //For DisplayLabel
                        using Display = DisplayLabel;
                        {
                            e.setColor(Display::Text, QColor("#004d40"));
                            e.setColor(Display::Panel, QColor("#b2dfdb"));
                            e.setMetric(Display::Panel | QskAspect::Border, 2);
                            e.setColor(Display::Panel | QskAspect::Border, Qt::black);
                            e.setAlignment(Display::Text, Qt::AlignRight);
                            e.setBoxShape(Display::Panel, 8);
                            e.setPadding(Display::Panel, QskMargins(25));
                        }   

                        //For OtherButtons
                        using Other = OtherButtons;
                        {
                            e.setGradient(Other::Panel, QColor("#add8e6"));  
                            e.setColor(Other::Text, Qt::black);
                            e.setGradient(Other::Panel | Other::Hovered, QColor("#579abe"));
                            e.setAnimation(Other::Panel | QskAspect::Color, 100);
                            e.setBoxShape(Other::Panel, 8);
                        }

                        //For NumberButtons
                        using Number = NumberButtons;
                        {
                            e.setGradient(Number::Panel, QColor("#b2e4b2")); 
                            e.setColor(Number::Text, Qt::black);
                            e.setGradient(Number::Panel | Number::Hovered, QColor("#03c03c"));
                            e.setAnimation(Number::Panel | QskAspect::Color, 100);
                            e.setBoxShape(Number::Panel, 8);
                        }

                        //For OperationButtons
                        using Operation = OperationButtons;
                        {
                            e.setGradient(Operation::Panel, QColor("#e0b0b0")); 
                            e.setColor(Operation::Text, Qt::black);
                            e.setGradient(Operation::Panel | Operation::Hovered, QColor("#c23b23"));
                            e.setAnimation(Operation::Panel | QskAspect::Color, 100);
                            e.setBoxShape(OperationButtons::Panel, 8);
                        }

                    }
                }
        };
    return new PastelSkin();
    }

    return nullptr;
}