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
#include <QskFontRole.h>

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
                        //This sets the whole system font to the following settings
                        setFont(QskFontRole::Body, QFont("Calibri", 14, QFont::Bold));

                        //For OtherButtons
                        e.setFontRole(OtherButtons::Text, {QskFontRole::Body, QskFontRole::High});
                        e.setGradient(OtherButtons::Panel, Qt::lightGray);  
                        e.setColor(OtherButtons::Text, Qt::black);
                        e.setGradient(OtherButtons::Panel | OtherButtons::Hovered, Qt::darkGray);
                        e.setAnimation(OtherButtons::Panel | QskAspect::Color, 100);
                        e.setBoxShape(OtherButtons::Panel, 8);
                       // e.setMargin(OtherButtons::Panel, myMargin->isEquidistant());

                        //For NumberButtons
                        e.setGradient(NumberButtons::Panel, Qt::green); 
                        e.setColor(NumberButtons::Text, Qt::black);
                        e.setGradient(NumberButtons::Panel | NumberButtons::Hovered, Qt::darkGreen);
                        e.setAnimation(NumberButtons::Panel | QskAspect::Color, 100);
                        e.setBoxShape(NumberButtons::Panel, 8);
                        //e.setMargin(NumberButtons::Panel, myMargin->isEquidistant());
                        
                        //For OperationButtons
                        e.setGradient(OperationButtons::Panel, Qt::red); 
                        e.setColor(OperationButtons::Text, Qt::black);
                        e.setGradient(OperationButtons::Panel | OperationButtons::Hovered, Qt::darkRed);
                        e.setAnimation(OperationButtons::Panel | QskAspect::Color, 100);
                        e.setBoxShape(OperationButtons::Panel, 8);
                        // e.setMargin(OperationButtons::Panel, myMargin->isEquidistant());

                    }
                }
        };
    return new GeneralButtonSkin();
    }

    return nullptr;
}