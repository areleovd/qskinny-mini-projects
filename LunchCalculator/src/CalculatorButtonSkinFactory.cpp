#include "CalculatorButtonSkinFactory.h"
#include <QskAspect.h>
#include <QskPushButton.h>
#include <QskSkin.h>
#include <QskSkinnable.h>
#include <QskSkinHintTableEditor.h>
#include <qnamespace.h>
#include "NumberButtons.h"
#include "OperationButtons.h"
#include "OtherButtons.h"

CalculatorButtonSkinFactory::CalculatorButtonSkinFactory(QObject* parent) : QskSkinFactory(parent)
{
}

QStringList CalculatorButtonSkinFactory::skinNames() const
{
        return{"GeneralButtonSkin"};
}

QskSkin* CalculatorButtonSkinFactory::createSkin(const QString& skinName) 
{
    if(skinName == "GeneralButtonSkin")
    {
        class GeneralButtonSkin : public QskSkin
        {
            protected:
                void initHints() override
                {
                    auto* myMargin = new QskMargins;
                    QskSkinHintTableEditor e(&hintTable());
                    {
                        
                        e.setGradient(OtherButtons::Panel, Qt::lightGray);  
                        e.setColor(OtherButtons::Text, Qt::black);
                        e.setGradient(OtherButtons::Panel | OtherButtons::Hovered, Qt::gray);
                        e.setAnimation(OtherButtons::Panel | QskAspect::Color, 100);
                       // e.setMargin(OtherButtons::Panel, myMargin->isEquidistant());


                        e.setGradient(NumberButtons::Panel, Qt::magenta); 
                        e.setColor(NumberButtons::Text, Qt::black);
                        e.setGradient(NumberButtons::Panel | NumberButtons::Hovered, Qt::darkMagenta);
                        e.setAnimation(NumberButtons::Panel | QskAspect::Color, 100);
                        //e.setMargin(NumberButtons::Panel, myMargin->isEquidistant());
                        // e.set 
                        e.setGradient(OperationButtons::Panel, Qt::red); 
                        e.setColor(OperationButtons::Text, Qt::black);
                        e.setGradient(OperationButtons::Panel | OperationButtons::Hovered, Qt::darkRed);
                        e.setAnimation(OperationButtons::Panel | QskAspect::Color, 100);
                        // e.setMargin(OperationButtons::Panel, myMargin->isEquidistant());

                    }
                }
        };
    return new GeneralButtonSkin();
    }

    return nullptr;
}