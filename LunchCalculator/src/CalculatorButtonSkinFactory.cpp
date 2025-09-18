#include "CalculatorButtonSkinFactory.h"
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
                        // e.setFontRole(OtherButtons::Text, {QskFontRole::Body, QskFontRole::High});
                        e.setGradient(OtherButtons::Panel, QColor("#add8e6"));  
                        e.setColor(OtherButtons::Text, Qt::black);
                        e.setGradient(OtherButtons::Panel | OtherButtons::Hovered, QColor("#579abe"));
                        e.setAnimation(OtherButtons::Panel | QskAspect::Color, 100);
                        e.setBoxShape(OtherButtons::Panel, 8);
                       // e.setMargin(OtherButtons::Panel, myMargin->isEquidistant());

                        //For NumberButtons
                        e.setGradient(NumberButtons::Panel, QColor("#b2e4b2")); 
                        e.setColor(NumberButtons::Text, Qt::black);
                        e.setGradient(NumberButtons::Panel | NumberButtons::Hovered, QColor("#03c03c"));
                        e.setAnimation(NumberButtons::Panel | QskAspect::Color, 100);
                        e.setBoxShape(NumberButtons::Panel, 8);
                        //e.setMargin(NumberButtons::Panel, myMargin->isEquidistant());
                        
                        //For OperationButtons
                        e.setGradient(OperationButtons::Panel, QColor("#e0b0b0")); 
                        e.setColor(OperationButtons::Text, Qt::black);
                        e.setGradient(OperationButtons::Panel | OperationButtons::Hovered, QColor("#c23b23"));
                        e.setAnimation(OperationButtons::Panel | QskAspect::Color, 100);
                        e.setBoxShape(OperationButtons::Panel, 8);
                        // e.setMargin(OperationButtons::Panel, myMargin->isEquidistant());

                        //For DisplayLabel
                        e.setColor(DisplayLabel::Text, QColor("#004d40"));
                        e.setColor(DisplayLabel::Panel, QColor("#b2dfdb"));
                        e.setMetric(DisplayLabel::Panel | QskAspect::Border, 2);
                        e.setColor(DisplayLabel::Panel | QskAspect::Border, Qt::black);
                        e.setAlignment(DisplayLabel::Text, Qt::AlignRight);
                        // e.setMargin(DisplayLabel::Panel, QskMargins(15));
                        e.setBoxShape(DisplayLabel::Panel, 8);
                        e.setPadding(DisplayLabel::Panel, QskMargins(25));
                        // e.setBoxBorderMetrics(DisplayLabel::Panel, 8);
                        





                    }
                }
        };
    return new GeneralButtonSkin();
    }

    return nullptr;
}