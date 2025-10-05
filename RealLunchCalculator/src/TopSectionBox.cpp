#include "TopSectionBox.h"

#include <QskLinearBox.h>
#include <QskSkinnable.h>
#include <QskTextLabel.h>
#include <QskTextField.h>
#include <QskComboBox.h>
#include <QskLabelData.h>
#include <QskBoxBorderMetrics.h>
#include <QskBoxShapeMetrics.h>
#include <qnamespace.h>
#include <qquickitem.h>

TopSectionBox::TopSectionBox() : QskLinearBox()
{
    
    this->setOrientation(Qt::Vertical);
    // this->setSpacing(0);
    this->setPadding(20);
    this->setPanel(true);
    this->setBoxBorderMetricsHint(QskLinearBox::Panel, QskBoxBorderMetrics(2));
    this->setBoxShapeHint(QskLinearBox::Panel,QskBoxShapeMetrics(8));
    this->setColor(QskLinearBox::Panel, QColor("#b5ead7"));

    
    for (int row = 0; row < 3; row++)
    {
        auto* horizontalBox = new QskLinearBox(Qt::Horizontal);
        horizontalBox->setFixedHeight(50);
        if (row == 0)
        {
            auto* totalBillLabel = new QskTextLabel("Total Bill: ");
            auto* totalBillInputField = new QskTextField("Empty too");
            horizontalBox->addItem(totalBillLabel);
            horizontalBox->addItem((totalBillInputField));
        }
        else if (row == 1)
        {
            auto* sstLabel = new QskTextLabel("SST: ", horizontalBox);
            auto* sstInputField = new QskTextField("Emptyyy", horizontalBox);
        }
        else
        {
            auto* payerLabel = new QskTextLabel("Paid by: ", horizontalBox);
            auto* payerSelectComboBox = new QskComboBox(horizontalBox);
            payerSelectComboBox->setPlaceholderText("Empty List");
            QVector<QskLabelData> options = {QskLabelData("Apple"), QskLabelData("Boy")};
            payerSelectComboBox->setOptions(options);
        }
        
        this->addItem(horizontalBox);
    }



}