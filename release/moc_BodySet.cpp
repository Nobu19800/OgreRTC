/****************************************************************************
** Meta object code from reading C++ file 'BodySet.h'
**
** Created: Sun Feb 9 23:52:24 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BodySet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BodySet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BodySetWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      28,   14,   14,   14, 0x0a,
      51,   41,   14,   14, 0x0a,
      91,   87,   14,   14, 0x0a,
     120,   87,   14,   14, 0x0a,
     151,   14,   14,   14, 0x08,
     167,  161,   14,   14, 0x08,
     181,  161,   14,   14, 0x08,
     198,  161,   14,   14, 0x08,
     215,  161,   14,   14, 0x08,
     232,  161,   14,   14, 0x08,
     251,  161,   14,   14, 0x08,
     270,  161,   14,   14, 0x08,
     289,  161,   14,   14, 0x08,
     306,  161,   14,   14, 0x08,
     324,  161,   14,   14, 0x08,
     340,  161,   14,   14, 0x08,
     356,  161,   14,   14, 0x08,
     374,  161,   14,   14, 0x08,
     391,  161,   14,   14, 0x08,
     409,  161,   14,   14, 0x08,
     431,   14,   14,   14, 0x08,
     445,   14,   14,   14, 0x08,
     461,   14,   14,   14, 0x08,
     480,   14,   14,   14, 0x08,
     501,   14,   14,   14, 0x08,
     515,   14,   14,   14, 0x08,
     531,   14,   14,   14, 0x08,
     550,   14,   14,   14, 0x08,
     571,   14,   14,   14, 0x08,
     595,   14,   14,   14, 0x08,
     610,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BodySetWidget[] = {
    "BodySetWidget\0\0UpdateBody()\0UpdateList()\0"
    "evt,dx,dy\0mouseMoveSlot(QMouseEvent*,int,int)\0"
    "evt\0mousePressSlot(QMouseEvent*)\0"
    "mouseReleaseSlot(QMouseEvent*)\0SetSlot()\0"
    "value\0NameSlot(int)\0PosXSlot(double)\0"
    "PosYSlot(double)\0PosZSlot(double)\0"
    "ScaleXSlot(double)\0ScaleYSlot(double)\0"
    "ScaleZSlot(double)\0RollSlot(double)\0"
    "PitchSlot(double)\0YawSlot(double)\0"
    "RedSlot(double)\0GreenSlot(double)\0"
    "BlueSlot(double)\0AlphaSlot(double)\0"
    "AnimationSlot(double)\0VisibleSlot()\0"
    "unVisibleSlot()\0SetAnimationSlot()\0"
    "ResetAnimationSlot()\0DestroySlot()\0"
    "SetShadowSlot()\0RemoveShadowSlot()\0"
    "SetBoundingBoxSlot()\0RemoveBoundingBoxSlot()\0"
    "MaterialSlot()\0SetMaterialSlot()\0"
};

const QMetaObject BodySetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BodySetWidget,
      qt_meta_data_BodySetWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BodySetWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BodySetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BodySetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BodySetWidget))
        return static_cast<void*>(const_cast< BodySetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int BodySetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: UpdateBody(); break;
        case 1: UpdateList(); break;
        case 2: mouseMoveSlot((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: mousePressSlot((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: mouseReleaseSlot((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: SetSlot(); break;
        case 6: NameSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: PosXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: PosYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: PosZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: ScaleXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: ScaleYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: ScaleZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: RollSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: PitchSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: YawSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: RedSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: GreenSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: BlueSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: AlphaSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: AnimationSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 21: VisibleSlot(); break;
        case 22: unVisibleSlot(); break;
        case 23: SetAnimationSlot(); break;
        case 24: ResetAnimationSlot(); break;
        case 25: DestroySlot(); break;
        case 26: SetShadowSlot(); break;
        case 27: RemoveShadowSlot(); break;
        case 28: SetBoundingBoxSlot(); break;
        case 29: RemoveBoundingBoxSlot(); break;
        case 30: MaterialSlot(); break;
        case 31: SetMaterialSlot(); break;
        default: ;
        }
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void BodySetWidget::UpdateBody()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
