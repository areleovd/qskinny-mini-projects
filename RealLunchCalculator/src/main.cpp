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
    auto* verticalTopSectionBox = new QskLinearBox(Qt::Vertical, verticalContainerBox);
    auto* horizontalMiscBoxRow1 = new QskLinearBox (Qt::Horizontal, verticalTopSectionBox);
    //TODO: Place label and input field for total bill here
    auto* totalBillLabel = new QskTextLabel("Total Bill: ", horizontalMiscBoxRow1);
    auto* totalBillInputField = new QskTextField("Test",horizontalMiscBoxRow1);
    auto* horizontalMiscBoxRow2 = new QskLinearBox (Qt::Horizontal, verticalTopSectionBox);
    //TODO: Place label and input field for SST here
    auto* sstLabel = new QskTextLabel("SST: ", horizontalMiscBoxRow2);
    auto* sstInputField = new QskTextField("Test2",horizontalMiscBoxRow2);
    auto* horizontalMiscBoxRow3 = new QskLinearBox (Qt::Horizontal, verticalTopSectionBox);
    //TODO: Place label and dropdown box for payer here
    auto* payerLabel = new QskTextLabel("Paid by: ", horizontalMiscBoxRow3);
    auto* payerSelectComboBox = new QskComboBox(horizontalMiscBoxRow3);
    payerSelectComboBox->setPlaceholderText("Test dropdown");
    QVector<QskLabelData> options = {QskLabelData("Apple"), QskLabelData("Boy")};
    payerSelectComboBox->setOptions(options);


    
    //Bottom Section Boxes
    auto* verticalBottomSectionBox = new QskLinearBox(Qt::Vertical, verticalContainerBox);
    //TODO: Place table with verticalBottomSectionBox as the parent
    auto* debtorScrollView = new QskScrollView(verticalBottomSectionBox);
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