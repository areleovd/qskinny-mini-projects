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

#include "MainView.h"
 
int main( int argc, char* argv[] )
{
    QGuiApplication app( argc, argv );
 
    QskWindow window;
    window.setTitle("Mim's Lunch Calculator");
    window.addItem(new MainView());
    window.resize(1280,800);
    window.show();
 
    return app.exec();
}