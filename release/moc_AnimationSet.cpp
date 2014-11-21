/****************************************************************************
** Meta object code from reading C++ file 'AnimationSet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AnimationSet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AnimationSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AnimationSetWidget_t {
    QByteArrayData data[22];
    char stringdata[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnimationSetWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnimationSetWidget_t qt_meta_stringdata_AnimationSetWidget = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 15),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 10),
QT_MOC_LITERAL(4, 47, 7),
QT_MOC_LITERAL(5, 55, 8),
QT_MOC_LITERAL(6, 64, 5),
QT_MOC_LITERAL(7, 70, 11),
QT_MOC_LITERAL(8, 82, 9),
QT_MOC_LITERAL(9, 92, 8),
QT_MOC_LITERAL(10, 101, 8),
QT_MOC_LITERAL(11, 110, 8),
QT_MOC_LITERAL(12, 119, 8),
QT_MOC_LITERAL(13, 128, 9),
QT_MOC_LITERAL(14, 138, 7),
QT_MOC_LITERAL(15, 146, 7),
QT_MOC_LITERAL(16, 154, 13),
QT_MOC_LITERAL(17, 168, 10),
QT_MOC_LITERAL(18, 179, 9),
QT_MOC_LITERAL(19, 189, 7),
QT_MOC_LITERAL(20, 197, 9),
QT_MOC_LITERAL(21, 207, 8)
    },
    "AnimationSetWidget\0UpdateAnimation\0\0"
    "UpdateList\0SetSlot\0NameSlot\0value\0"
    "DestroySlot\0ResetSlot\0PosXSlot\0PosYSlot\0"
    "PosZSlot\0RollSlot\0PitchSlot\0YawSlot\0"
    "KeySlot\0RemoveKeySlot\0KeyNumSlot\0"
    "TransSlot\0RotSlot\0StateSlot\0TimeSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnimationSetWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  110,    2, 0x0a /* Public */,
       4,    0,  111,    2, 0x08 /* Private */,
       5,    1,  112,    2, 0x08 /* Private */,
       7,    0,  115,    2, 0x08 /* Private */,
       8,    0,  116,    2, 0x08 /* Private */,
       9,    1,  117,    2, 0x08 /* Private */,
      10,    1,  120,    2, 0x08 /* Private */,
      11,    1,  123,    2, 0x08 /* Private */,
      12,    1,  126,    2, 0x08 /* Private */,
      13,    1,  129,    2, 0x08 /* Private */,
      14,    1,  132,    2, 0x08 /* Private */,
      15,    0,  135,    2, 0x08 /* Private */,
      16,    0,  136,    2, 0x08 /* Private */,
      17,    1,  137,    2, 0x08 /* Private */,
      18,    0,  140,    2, 0x08 /* Private */,
      19,    0,  141,    2, 0x08 /* Private */,
      20,    1,  142,    2, 0x08 /* Private */,
      21,    1,  145,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,

       0        // eod
};

void AnimationSetWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AnimationSetWidget *_t = static_cast<AnimationSetWidget *>(_o);
        switch (_id) {
        case 0: _t->UpdateAnimation(); break;
        case 1: _t->UpdateList(); break;
        case 2: _t->SetSlot(); break;
        case 3: _t->NameSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->DestroySlot(); break;
        case 5: _t->ResetSlot(); break;
        case 6: _t->PosXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->PosYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->PosZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->RollSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->PitchSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->YawSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->KeySlot(); break;
        case 13: _t->RemoveKeySlot(); break;
        case 14: _t->KeyNumSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->TransSlot(); break;
        case 16: _t->RotSlot(); break;
        case 17: _t->StateSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->TimeSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AnimationSetWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AnimationSetWidget::UpdateAnimation)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject AnimationSetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AnimationSetWidget.data,
      qt_meta_data_AnimationSetWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *AnimationSetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnimationSetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AnimationSetWidget.stringdata))
        return static_cast<void*>(const_cast< AnimationSetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AnimationSetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void AnimationSetWidget::UpdateAnimation()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
