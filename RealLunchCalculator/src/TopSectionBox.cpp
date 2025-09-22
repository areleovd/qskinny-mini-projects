#include "TopSectionBox.h"

#include <QskLinearBox.h>
#include <QskTextLabel.h>
#include <QskTextField.h>
#include <QskComboBox.h>
#include <QskLabelData.h>
#include <qnamespace.h>
#include <qquickitem.h>

TopSectionBox::TopSectionBox(QQuickItem* parent) : QskLinearBox(parent)
{
    
    this->setOrientation(Qt::Vertical);
    
    for (int row = 0; row < 3; row++)
    {
        auto* horizontalBox = new QskLinearBox(Qt::Horizontal, this);
        if (row == 0)
        {
            auto* totalBillLabel = new QskTextLabel("Total Bill: ", horizontalBox);
            auto* totalBillInputField = new QskTextField("Empty too", horizontalBox);
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
    }
}