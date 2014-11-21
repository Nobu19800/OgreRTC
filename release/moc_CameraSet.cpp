/****************************************************************************
** Meta object code from reading C++ file 'CameraSet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CameraSet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CameraSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CameraSetWidget_t {
    QByteArrayData data[24];
    char stringdata[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CameraSetWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CameraSetWidget_t qt_meta_stringdata_CameraSetWidget = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 10),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 13),
QT_MOC_LITERAL(4, 42, 12),
QT_MOC_LITERAL(5, 55, 3),
QT_MOC_LITERAL(6, 59, 2),
QT_MOC_LITERAL(7, 62, 2),
QT_MOC_LITERAL(8, 65, 14),
QT_MOC_LITERAL(9, 80, 16),
QT_MOC_LITERAL(10, 97, 10),
QT_MOC_LITERAL(11, 108, 5),
QT_MOC_LITERAL(12, 114, 10),
QT_MOC_LITERAL(13, 125, 10),
QT_MOC_LITERAL(14, 136, 11),
QT_MOC_LITERAL(15, 148, 11),
QT_MOC_LITERAL(16, 160, 11),
QT_MOC_LITERAL(17, 172, 8),
QT_MOC_LITERAL(18, 181, 8),
QT_MOC_LITERAL(19, 190, 8),
QT_MOC_LITERAL(20, 199, 8),
QT_MOC_LITERAL(21, 208, 9),
QT_MOC_LITERAL(22, 218, 7),
QT_MOC_LITERAL(23, 226, 7)
    },
    "CameraSetWidget\0UpdateList\0\0mouseMoveSlot\0"
    "QMouseEvent*\0evt\0dx\0dy\0mousePressSlot\0"
    "mouseReleaseSlot\0LightXSlot\0value\0"
    "LightYSlot\0LightZSlot\0ShadowRSlot\0"
    "ShadowGSlot\0ShadowBSlot\0PosXSlot\0"
    "PosYSlot\0PosZSlot\0RollSlot\0PitchSlot\0"
    "YawSlot\0LenSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraSetWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x0a /* Public */,
       3,    3,  100,    2, 0x0a /* Public */,
       8,    1,  107,    2, 0x0a /* Public */,
       9,    1,  110,    2, 0x0a /* Public */,
      10,    1,  113,    2, 0x08 /* Private */,
      12,    1,  116,    2, 0x08 /* Private */,
      13,    1,  119,    2, 0x08 /* Private */,
      14,    1,  122,    2, 0x08 /* Private */,
      15,    1,  125,    2, 0x08 /* Private */,
      16,    1,  128,    2, 0x08 /* Private */,
      17,    1,  131,    2, 0x08 /* Private */,
      18,    1,  134,    2, 0x08 /* Private */,
      19,    1,  137,    2, 0x08 /* Private */,
      20,    1,  140,    2, 0x08 /* Private */,
      21,    1,  143,    2, 0x08 /* Private */,
      22,    1,  146,    2, 0x08 /* Private */,
      23,    1,  149,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int, QMetaType::Int,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,

       0        // eod
};

void CameraSetWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraSetWidget *_t = static_cast<CameraSetWidget *>(_o);
        switch (_id) {
        case 0: _t->UpdateList(); break;
        case 1: _t->mouseMoveSlot((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->mousePressSlot((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->mouseReleaseSlot((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->LightXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->LightYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->LightZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->ShadowRSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->ShadowGSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->ShadowBSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->PosXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->PosYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->PosZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->RollSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->PitchSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->YawSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->LenSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CameraSetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CameraSetWidget.data,
      qt_meta_data_CameraSetWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *CameraSetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraSetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CameraSetWidget.stringdata))
        return static_cast<void*>(const_cast< CameraSetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CameraSetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
