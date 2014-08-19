/****************************************************************************
** Meta object code from reading C++ file 'AnimationSet.h'
**
** Created: Tue Aug 19 09:04:21 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AnimationSet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AnimationSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AnimationSetWidget[] = {

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
      20,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   19,   19,   19, 0x0a,
      51,   19,   19,   19, 0x08,
      67,   61,   19,   19, 0x08,
      81,   19,   19,   19, 0x08,
      95,   19,   19,   19, 0x08,
     107,   61,   19,   19, 0x08,
     124,   61,   19,   19, 0x08,
     141,   61,   19,   19, 0x08,
     158,   61,   19,   19, 0x08,
     175,   61,   19,   19, 0x08,
     193,   61,   19,   19, 0x08,
     209,   19,   19,   19, 0x08,
     219,   19,   19,   19, 0x08,
     235,   61,   19,   19, 0x08,
     251,   19,   19,   19, 0x08,
     263,   19,   19,   19, 0x08,
     273,   61,   19,   19, 0x08,
     291,   61,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AnimationSetWidget[] = {
    "AnimationSetWidget\0\0UpdateAnimation()\0"
    "UpdateList()\0SetSlot()\0value\0NameSlot(int)\0"
    "DestroySlot()\0ResetSlot()\0PosXSlot(double)\0"
    "PosYSlot(double)\0PosZSlot(double)\0"
    "RollSlot(double)\0PitchSlot(double)\0"
    "YawSlot(double)\0KeySlot()\0RemoveKeySlot()\0"
    "KeyNumSlot(int)\0TransSlot()\0RotSlot()\0"
    "StateSlot(double)\0TimeSlot(double)\0"
};

const QMetaObject AnimationSetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AnimationSetWidget,
      qt_meta_data_AnimationSetWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AnimationSetWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AnimationSetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AnimationSetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AnimationSetWidget))
        return static_cast<void*>(const_cast< AnimationSetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AnimationSetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: UpdateAnimation(); break;
        case 1: UpdateList(); break;
        case 2: SetSlot(); break;
        case 3: NameSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: DestroySlot(); break;
        case 5: ResetSlot(); break;
        case 6: PosXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: PosYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: PosZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: RollSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: PitchSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: YawSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: KeySlot(); break;
        case 13: RemoveKeySlot(); break;
        case 14: KeyNumSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: TransSlot(); break;
        case 16: RotSlot(); break;
        case 17: StateSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: TimeSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
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
