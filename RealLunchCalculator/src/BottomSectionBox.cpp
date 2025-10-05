#include "BottomSectionBox.h"

#include <QskBoxShapeMetrics.h>
#include <QskLinearBox.h>
#include <QskGridBox.h>
#include <QskPushButton.h>
#include <QskTextLabel.h>
#include <qnamespace.h>

BottomSectionBox::BottomSectionBox() : QskLinearBox()
{
    this->setOrientation(Qt::Vertical);
    this->setPanel(true);
    this->setColor(QskLinearBox::Panel, QColor("#e2f0cb"));

    auto* gridBoxDebtor = new QskGridBox();
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            QString txt = QString("R%1C%2").arg(row + 1).arg(col + 1);
            auto* cell = new QskTextLabel(txt);

            gridBoxDebtor->addItem(cell, row, col);
        }
    }

 
    auto* horizontalButtonsBox = new QskLinearBox(Qt::Horizontal);
    horizontalButtonsBox->setPanel(true);
    horizontalButtonsBox->setFixedSize(400,75);
    horizontalButtonsBox->setPadding(20);

    horizontalButtonsBox->setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(8));
    horizontalButtonsBox->setColor(QskLinearBox::Panel, QColor("#c7ceea"));

    //TODO: Place add person and remove person buttons
    auto* addPersonButton = new QskPushButton("Add person", horizontalButtonsBox);
    auto* removePersonButton = new QskPushButton("Remove person", horizontalButtonsBox);
    
    this->addItem(gridBoxDebtor);
    this->addItem(horizontalButtonsBox);
}