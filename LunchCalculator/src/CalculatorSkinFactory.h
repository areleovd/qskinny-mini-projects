#ifndef CALCULATORSKINFACTORY_H
#define CALCULATORSKINFACTORY_H
#include <QskSkin.h>

#include <QskGradient.h>
#include <QskPushButton.h>
#include <QskSkin.h>
#include <QskSkinHintTableEditor.h>
#include <QskSkinnable.h>
#include <QskSkinFactory.h>
#include <QskSkinManager.h>
#include <QskMargins.h>


class CalculatorSkinFactory : public QskSkinFactory
{
    Q_OBJECT
    
public:
    CalculatorSkinFactory(QObject* parent = nullptr);
    
    QStringList skinNames() const override;

    QskSkin* createSkin(const QString& skinName) override;

};

#endif //CALCULATORSKINFACTORY_H