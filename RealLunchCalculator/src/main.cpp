#include "TopSectionBox.h"
#include <QskScrollView.h>
#include <QskWindow.h>
#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <QskTextLabel.h>
#include <QskTextInput.h>
#include <QskTextField.h>
#include <QskLabelData.h>
#include <QskComboBox.h>
#include <QStandardItemModel>
#include <QskListView.h>
#include <QskGridBox.h>

#include <QGuiApplication>
#include <qnamespace.h>

 
int main( int argc, char* argv[] )
{
    QGuiApplication app( argc, argv );
 
    auto* verticalContainerBox = new QskLinearBox( Qt::Vertical );
    verticalContainerBox->setPanel( true );
    //Top Section Boxes
    auto topBox = new TopSectionBox(verticalContainerBox);


    //Bottom Section Boxes
    auto* verticalBottomSectionBox = new QskLinearBox(Qt::Vertical, verticalContainerBox);
    //TODO: Place table with verticalBottomSectionBox as the parent
    auto* gridBoxDebtor = new QskGridBox(verticalBottomSectionBox);
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            QString txt = QString("R%1C%2").arg(row + 1).arg(col + 1);
            auto* cell = new QskTextLabel(txt);

            gridBoxDebtor->addItem(cell, row, col);
        }
    }

 
    auto* horizontalButtonsBox = new QskLinearBox(Qt::Horizontal, verticalBottomSectionBox);
    //TODO: Place add person and remove person buttons
    auto* addPersonButton = new QskPushButton("Add person", horizontalButtonsBox);
    auto* removePersonButton = new QskPushButton("Remove person", horizontalButtonsBox);


    QskWindow window;
    window.addItem( verticalContainerBox );
    window.show();
 
    return app.exec();
}