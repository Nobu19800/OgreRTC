/****************************************************************************
** Meta object code from reading C++ file 'LightSet.h'
**
** Created: Tue Aug 19 09:03:43 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LightSet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LightSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LightSetWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   15,   15,   15, 0x0a,
      43,   15,   15,   15, 0x08,
      59,   53,   15,   15, 0x08,
      73,   53,   15,   15, 0x08,
      90,   53,   15,   15, 0x08,
     107,   53,   15,   15, 0x08,
     124,   53,   15,   15, 0x08,
     140,   53,   15,   15, 0x08,
     158,   53,   15,   15, 0x08,
     175,   15,   15,   15, 0x08,
     189,   15,   15,   15, 0x08,
     205,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LightSetWidget[] = {
    "LightSetWidget\0\0UpdateLight()\0"
    "UpdateList()\0SetSlot()\0value\0NameSlot(int)\0"
    "PosXSlot(double)\0PosYSlot(double)\0"
    "PosZSlot(double)\0RedSlot(double)\0"
    "GreenSlot(double)\0BlueSlot(double)\0"
    "VisibleSlot()\0unVisibleSlot()\0"
    "DestroySlot()\0"
};

const QMetaObject LightSetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LightSetWidget,
      qt_meta_data_LightSetWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LightSetWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LightSetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LightSetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LightSetWidget))
        return static_cast<void*>(const_cast< LightSetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int LightSetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: UpdateLight(); break;
        case 1: UpdateList(); break;
        case 2: SetSlot(); break;
        case 3: NameSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: PosXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: PosYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: PosZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: RedSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: GreenSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: BlueSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: VisibleSlot(); break;
        case 11: unVisibleSlot(); break;
        case 12: DestroySlot(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void LightSetWidget::UpdateLight()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
