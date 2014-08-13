/****************************************************************************
** Meta object code from reading C++ file 'SimBodySet.h'
**
** Created: Sun Feb 9 23:50:21 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SimBodySet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SimBodySet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SimBodySetWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   17,   17,   17, 0x0a,
      47,   17,   17,   17, 0x08,
      63,   57,   17,   17, 0x08,
      77,   57,   17,   17, 0x08,
      94,   57,   17,   17, 0x08,
     111,   57,   17,   17, 0x08,
     128,   57,   17,   17, 0x08,
     146,   57,   17,   17, 0x08,
     164,   57,   17,   17, 0x08,
     182,   57,   17,   17, 0x08,
     200,   57,   17,   17, 0x08,
     219,   57,   17,   17, 0x08,
     238,   57,   17,   17, 0x08,
     257,   57,   17,   17, 0x08,
     277,   57,   17,   17, 0x08,
     297,   57,   17,   17, 0x08,
     317,   57,   17,   17, 0x08,
     334,   57,   17,   17, 0x08,
     352,   57,   17,   17, 0x08,
     368,   57,   17,   17, 0x08,
     385,   17,   17,   17, 0x08,
     399,   17,   17,   17, 0x08,
     415,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SimBodySetWidget[] = {
    "SimBodySetWidget\0\0UpdateODEBody()\0"
    "UpdateList()\0SetSlot()\0value\0NameSlot(int)\0"
    "PosXSlot(double)\0PosYSlot(double)\0"
    "PosZSlot(double)\0SizeXSlot(double)\0"
    "SizeYSlot(double)\0SizeZSlot(double)\0"
    "SizeRSlot(double)\0ScaleXSlot(double)\0"
    "ScaleYSlot(double)\0ScaleZSlot(double)\0"
    "OffsetXSlot(double)\0OffsetYSlot(double)\0"
    "OffsetZSlot(double)\0RollSlot(double)\0"
    "PitchSlot(double)\0YawSlot(double)\0"
    "MassSlot(double)\0VisibleSlot()\0"
    "unVisibleSlot()\0DestroySlot()\0"
};

const QMetaObject SimBodySetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SimBodySetWidget,
      qt_meta_data_SimBodySetWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SimBodySetWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SimBodySetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SimBodySetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SimBodySetWidget))
        return static_cast<void*>(const_cast< SimBodySetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SimBodySetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: UpdateODEBody(); break;
        case 1: UpdateList(); break;
        case 2: SetSlot(); break;
        case 3: NameSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: PosXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: PosYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: PosZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: SizeXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: SizeYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: SizeZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: SizeRSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: ScaleXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: ScaleYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: ScaleZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: OffsetXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: OffsetYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: OffsetZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: RollSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: PitchSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: YawSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: MassSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 21: VisibleSlot(); break;
        case 22: unVisibleSlot(); break;
        case 23: DestroySlot(); break;
        default: ;
        }
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void SimBodySetWidget::UpdateODEBody()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
