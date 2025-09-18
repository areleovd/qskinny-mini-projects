/* This is a program to create a lunch calculator
Author: Nurul Farah Shamimi
Date created: 25 August 2025
*/
#include <QskGradient.h>
#include <QskAspect.h>
#include <QskSizePolicy.h>
#include <QskWindow.h>
#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <QskTextLabel.h> 
#include <QGuiApplication>
#include <QskSkin.h>
#include <QskSkinHintTableEditor.h>
#include <QskSetup.h>
#include <QskSkinnable.h>
#include <QskSkinFactory.h>
#include <QskSkinManager.h>
#include <QskSetup.h>
#include <QskGraphic.h>
#include <QskGraphicLabel.h>
#include <QskFontRole.h>
#include <QskMargins.h>
#include <qnamespace.h>
#include <QskGridBox.h>

/*
    My Class Implementation
*/
#include "CalculatorSkinFactory.h"
#include "DisplayLabel.h"
#include "ButtonsGridBox.h"


int main( int argc, char* argv[] )
{
    QGuiApplication app( argc, argv );
    qskSkinManager->registerFactory("CalculatorSkinFactory", new CalculatorSkinFactory());
    qskSkinManager->setSkin("PastelSkin");
    
    
    /* Outer box of the calculator*/
    auto outerBox = new QskLinearBox( Qt::Vertical );
    outerBox->setPanel( true );
    outerBox->setBackgroundColor(QColor("#3b3b3b"));

    auto* displayLabel = new DisplayLabel("0", outerBox);

    /* Button box  of the calculator*/
    auto buttonsGridBox = new ButtonsGridBox(outerBox, displayLabel);
        
    /* Display the components */
    QskWindow window;
    window.addItem( outerBox );
    // window.resize(480,360);
    window.show();
 
    return app.exec();
}
#include "main.moc"