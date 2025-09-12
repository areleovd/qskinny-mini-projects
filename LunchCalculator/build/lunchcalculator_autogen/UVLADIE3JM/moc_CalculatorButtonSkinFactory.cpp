/****************************************************************************
** Meta object code from reading C++ file 'CalculatorButtonSkinFactory.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/CalculatorButtonSkinFactory.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CalculatorButtonSkinFactory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN27CalculatorButtonSkinFactoryE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN27CalculatorButtonSkinFactoryE = QtMocHelpers::stringData(
    "CalculatorButtonSkinFactory"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN27CalculatorButtonSkinFactoryE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject CalculatorButtonSkinFactory::staticMetaObject = { {
    QMetaObject::SuperData::link<QskSkinFactory::staticMetaObject>(),
    qt_meta_stringdata_ZN27CalculatorButtonSkinFactoryE.offsetsAndSizes,
    qt_meta_data_ZN27CalculatorButtonSkinFactoryE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN27CalculatorButtonSkinFactoryE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CalculatorButtonSkinFactory, std::true_type>
    >,
    nullptr
} };

void CalculatorButtonSkinFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<CalculatorButtonSkinFactory *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *CalculatorButtonSkinFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalculatorButtonSkinFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN27CalculatorButtonSkinFactoryE.stringdata0))
        return static_cast<void*>(this);
    return QskSkinFactory::qt_metacast(_clname);
}

int CalculatorButtonSkinFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QskSkinFactory::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
