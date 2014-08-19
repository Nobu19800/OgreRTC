/****************************************************************************
** Meta object code from reading C++ file 'OtherSet.h'
**
** Created: Tue Aug 19 09:03:20 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OtherSet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OtherSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OtherSetWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      29,   15,   15,   15, 0x08,
      45,   15,   15,   15, 0x08,
      70,   64,   15,   15, 0x08,
      90,   15,   15,   15, 0x08,
     105,   15,   15,   15, 0x08,
     123,   64,   15,   15, 0x08,
     142,   64,   15,   15, 0x08,
     160,   64,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OtherSetWidget[] = {
    "OtherSetWidget\0\0UpdateList()\0"
    "SkyBoxSetSlot()\0DelSkyBoxSetSlot()\0"
    "value\0SkyBoxSizeSlot(int)\0FloorSetSlot()\0"
    "DelFloorSetSlot()\0FloorSizeSlot(int)\0"
    "FloorDirSlot(int)\0TimeSlot(int)\0"
};

const QMetaObject OtherSetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OtherSetWidget,
      qt_meta_data_OtherSetWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OtherSetWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OtherSetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OtherSetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OtherSetWidget))
        return static_cast<void*>(const_cast< OtherSetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int OtherSetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: UpdateList(); break;
        case 1: SkyBoxSetSlot(); break;
        case 2: DelSkyBoxSetSlot(); break;
        case 3: SkyBoxSizeSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: FloorSetSlot(); break;
        case 5: DelFloorSetSlot(); break;
        case 6: FloorSizeSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: FloorDirSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: TimeSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
