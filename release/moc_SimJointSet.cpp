/****************************************************************************
** Meta object code from reading C++ file 'SimJointSet.h'
**
** Created: Sun Aug 31 14:08:48 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SimJointSet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SimJointSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SimJointSetWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   18,   18,   18, 0x0a,
      49,   18,   18,   18, 0x08,
      65,   59,   18,   18, 0x08,
      79,   59,   18,   18, 0x08,
      96,   59,   18,   18, 0x08,
     113,   59,   18,   18, 0x08,
     130,   59,   18,   18, 0x08,
     149,   59,   18,   18, 0x08,
     168,   59,   18,   18, 0x08,
     187,   59,   18,   18, 0x08,
     204,   59,   18,   18, 0x08,
     222,   59,   18,   18, 0x08,
     238,   59,   18,   18, 0x08,
     258,   59,   18,   18, 0x08,
     278,   59,   18,   18, 0x08,
     298,   18,   18,   18, 0x08,
     312,   18,   18,   18, 0x08,
     328,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SimJointSetWidget[] = {
    "SimJointSetWidget\0\0UpdateODEJoint()\0"
    "UpdateList()\0SetSlot()\0value\0NameSlot(int)\0"
    "PosXSlot(double)\0PosYSlot(double)\0"
    "PosZSlot(double)\0ScaleXSlot(double)\0"
    "ScaleYSlot(double)\0ScaleZSlot(double)\0"
    "RollSlot(double)\0PitchSlot(double)\0"
    "YawSlot(double)\0OffsetXSlot(double)\0"
    "OffsetYSlot(double)\0OffsetZSlot(double)\0"
    "VisibleSlot()\0unVisibleSlot()\0"
    "DestroySlot()\0"
};

const QMetaObject SimJointSetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SimJointSetWidget,
      qt_meta_data_SimJointSetWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SimJointSetWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SimJointSetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SimJointSetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SimJointSetWidget))
        return static_cast<void*>(const_cast< SimJointSetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SimJointSetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: UpdateODEJoint(); break;
        case 1: UpdateList(); break;
        case 2: SetSlot(); break;
        case 3: NameSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: PosXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: PosYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: PosZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: ScaleXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: ScaleYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: ScaleZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: RollSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: PitchSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: YawSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: OffsetXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: OffsetYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: OffsetZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: VisibleSlot(); break;
        case 17: unVisibleSlot(); break;
        case 18: DestroySlot(); break;
        default: ;
        }
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void SimJointSetWidget::UpdateODEJoint()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
