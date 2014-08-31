/****************************************************************************
** Meta object code from reading C++ file 'SubWindowSet.h'
**
** Created: Sun Aug 31 14:08:48 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SubWindowSet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SubWindowSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SubWindowSetWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      33,   19,   19,   19, 0x08,
      49,   43,   19,   19, 0x08,
      66,   43,   19,   19, 0x08,
      83,   43,   19,   19, 0x08,
     102,   43,   19,   19, 0x08,
     121,   19,   19,   19, 0x08,
     135,   19,   19,   19, 0x08,
     151,   19,   19,   19, 0x08,
     165,   43,   19,   19, 0x08,
     188,   43,   19,   19, 0x08,
     211,   43,   19,   19, 0x08,
     234,   43,   19,   19, 0x08,
     257,   43,   19,   19, 0x08,
     281,   43,   19,   19, 0x08,
     303,   43,   19,   19, 0x08,
     325,   19,   19,   19, 0x08,
     339,   19,   19,   19, 0x08,
     350,   43,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SubWindowSetWidget[] = {
    "SubWindowSetWidget\0\0UpdateList()\0"
    "SetSlot()\0value\0PosXSlot(double)\0"
    "PosYSlot(double)\0ScaleXSlot(double)\0"
    "ScaleYSlot(double)\0VisibleSlot()\0"
    "unVisibleSlot()\0DestroySlot()\0"
    "CameraPosXSlot(double)\0CameraPosYSlot(double)\0"
    "CameraPosZSlot(double)\0CameraRollSlot(double)\0"
    "CameraPitchSlot(double)\0CameraYawSlot(double)\0"
    "CameraLenSlot(double)\0RestartSlot()\0"
    "StopSlot()\0NameSlot(int)\0"
};

const QMetaObject SubWindowSetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SubWindowSetWidget,
      qt_meta_data_SubWindowSetWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SubWindowSetWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SubWindowSetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SubWindowSetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SubWindowSetWidget))
        return static_cast<void*>(const_cast< SubWindowSetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SubWindowSetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: UpdateList(); break;
        case 1: SetSlot(); break;
        case 2: PosXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: PosYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: ScaleXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: ScaleYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: VisibleSlot(); break;
        case 7: unVisibleSlot(); break;
        case 8: DestroySlot(); break;
        case 9: CameraPosXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: CameraPosYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: CameraPosZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: CameraRollSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: CameraPitchSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: CameraYawSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: CameraLenSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: RestartSlot(); break;
        case 17: StopSlot(); break;
        case 18: NameSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
