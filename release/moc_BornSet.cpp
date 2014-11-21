/****************************************************************************
** Meta object code from reading C++ file 'BornSet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BornSet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BornSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BornSetWidget_t {
    QByteArrayData data[16];
    char stringdata[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BornSetWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BornSetWidget_t qt_meta_stringdata_BornSetWidget = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 10),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 7),
QT_MOC_LITERAL(4, 34, 8),
QT_MOC_LITERAL(5, 43, 5),
QT_MOC_LITERAL(6, 49, 8),
QT_MOC_LITERAL(7, 58, 8),
QT_MOC_LITERAL(8, 67, 10),
QT_MOC_LITERAL(9, 78, 10),
QT_MOC_LITERAL(10, 89, 10),
QT_MOC_LITERAL(11, 100, 8),
QT_MOC_LITERAL(12, 109, 9),
QT_MOC_LITERAL(13, 119, 7),
QT_MOC_LITERAL(14, 127, 9),
QT_MOC_LITERAL(15, 137, 12)
    },
    "BornSetWidget\0UpdateBody\0\0SetSlot\0"
    "PosXSlot\0value\0PosYSlot\0PosZSlot\0"
    "ScaleXSlot\0ScaleYSlot\0ScaleZSlot\0"
    "RollSlot\0PitchSlot\0YawSlot\0ResetSlot\0"
    "BodyNameSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BornSetWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    1,   81,    2, 0x08 /* Private */,
       6,    1,   84,    2, 0x08 /* Private */,
       7,    1,   87,    2, 0x08 /* Private */,
       8,    1,   90,    2, 0x08 /* Private */,
       9,    1,   93,    2, 0x08 /* Private */,
      10,    1,   96,    2, 0x08 /* Private */,
      11,    1,   99,    2, 0x08 /* Private */,
      12,    1,  102,    2, 0x08 /* Private */,
      13,    1,  105,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    1,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void BornSetWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BornSetWidget *_t = static_cast<BornSetWidget *>(_o);
        switch (_id) {
        case 0: _t->UpdateBody(); break;
        case 1: _t->SetSlot(); break;
        case 2: _t->PosXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->PosYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->PosZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->ScaleXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->ScaleYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->ScaleZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->RollSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->PitchSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->YawSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->ResetSlot(); break;
        case 12: _t->BodyNameSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject BornSetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BornSetWidget.data,
      qt_meta_data_BornSetWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *BornSetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BornSetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BornSetWidget.stringdata))
        return static_cast<void*>(const_cast< BornSetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int BornSetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
