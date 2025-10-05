#include "MainView.h"
#include "TopSectionBox.h"
#include <QskLinearBox.h>
#include <qnamespace.h>

#include "TopSectionBox.h"
#include "BottomSectionBox.h"

MainView::MainView() : QskLinearBox()
{
    this->setOrientation(Qt::Vertical);
    this->setPanel(true);
    this->addItem(new TopSectionBox());
    this->addItem(new BottomSectionBox());
}