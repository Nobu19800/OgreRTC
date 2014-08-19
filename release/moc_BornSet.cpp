/****************************************************************************
** Meta object code from reading C++ file 'BornSet.h'
**
** Created: Tue Aug 19 09:04:10 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BornSet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BornSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BornSetWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      28,   14,   14,   14, 0x08,
      44,   38,   14,   14, 0x08,
      61,   38,   14,   14, 0x08,
      78,   38,   14,   14, 0x08,
      95,   38,   14,   14, 0x08,
     114,   38,   14,   14, 0x08,
     133,   38,   14,   14, 0x08,
     152,   38,   14,   14, 0x08,
     169,   38,   14,   14, 0x08,
     187,   38,   14,   14, 0x08,
     203,   14,   14,   14, 0x08,
     215,   38,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BornSetWidget[] = {
    "BornSetWidget\0\0UpdateBody()\0SetSlot()\0"
    "value\0PosXSlot(double)\0PosYSlot(double)\0"
    "PosZSlot(double)\0ScaleXSlot(double)\0"
    "ScaleYSlot(double)\0ScaleZSlot(double)\0"
    "RollSlot(double)\0PitchSlot(double)\0"
    "YawSlot(double)\0ResetSlot()\0"
    "BodyNameSlot(int)\0"
};

const QMetaObject BornSetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BornSetWidget,
      qt_meta_data_BornSetWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BornSetWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BornSetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BornSetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BornSetWidget))
        return static_cast<void*>(const_cast< BornSetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int BornSetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: UpdateBody(); break;
        case 1: SetSlot(); break;
        case 2: PosXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: PosYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: PosZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: ScaleXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: ScaleYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: ScaleZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: RollSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: PitchSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: YawSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: ResetSlot(); break;
        case 12: BodyNameSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
