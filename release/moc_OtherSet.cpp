/****************************************************************************
** Meta object code from reading C++ file 'OtherSet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OtherSet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OtherSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OtherSetWidget_t {
    QByteArrayData data[12];
    char stringdata[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OtherSetWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OtherSetWidget_t qt_meta_stringdata_OtherSetWidget = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 10),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 13),
QT_MOC_LITERAL(4, 41, 16),
QT_MOC_LITERAL(5, 58, 14),
QT_MOC_LITERAL(6, 73, 5),
QT_MOC_LITERAL(7, 79, 12),
QT_MOC_LITERAL(8, 92, 15),
QT_MOC_LITERAL(9, 108, 13),
QT_MOC_LITERAL(10, 122, 12),
QT_MOC_LITERAL(11, 135, 8)
    },
    "OtherSetWidget\0UpdateList\0\0SkyBoxSetSlot\0"
    "DelSkyBoxSetSlot\0SkyBoxSizeSlot\0value\0"
    "FloorSetSlot\0DelFloorSetSlot\0FloorSizeSlot\0"
    "FloorDirSlot\0TimeSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OtherSetWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    1,   62,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    1,   67,    2, 0x08 /* Private */,
      10,    1,   70,    2, 0x08 /* Private */,
      11,    1,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void OtherSetWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OtherSetWidget *_t = static_cast<OtherSetWidget *>(_o);
        switch (_id) {
        case 0: _t->UpdateList(); break;
        case 1: _t->SkyBoxSetSlot(); break;
        case 2: _t->DelSkyBoxSetSlot(); break;
        case 3: _t->SkyBoxSizeSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->FloorSetSlot(); break;
        case 5: _t->DelFloorSetSlot(); break;
        case 6: _t->FloorSizeSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->FloorDirSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->TimeSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject OtherSetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OtherSetWidget.data,
      qt_meta_data_OtherSetWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *OtherSetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OtherSetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OtherSetWidget.stringdata))
        return static_cast<void*>(const_cast< OtherSetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int OtherSetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
