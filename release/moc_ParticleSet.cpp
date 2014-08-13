/****************************************************************************
** Meta object code from reading C++ file 'ParticleSet.h'
**
** Created: Sun Feb 9 23:50:35 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ParticleSet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ParticleSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ParticleSetWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
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
      82,   59,   18,   18, 0x08,
      99,   59,   18,   18, 0x08,
     116,   59,   18,   18, 0x08,
     135,   59,   18,   18, 0x08,
     154,   59,   18,   18, 0x08,
     173,   59,   18,   18, 0x08,
     190,   59,   18,   18, 0x08,
     208,   59,   18,   18, 0x08,
     224,   18,   18,   18, 0x08,
     238,   18,   18,   18, 0x08,
     254,   18,   18,   18, 0x08,
     268,   59,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ParticleSetWidget[] = {
    "ParticleSetWidget\0\0UpdateParticle()\0"
    "UpdateList()\0SetSlot()\0value\0"
    "PosXSlot(double)\0PosYSlot(double)\0"
    "PosZSlot(double)\0ScaleXSlot(double)\0"
    "ScaleYSlot(double)\0ScaleZSlot(double)\0"
    "RollSlot(double)\0PitchSlot(double)\0"
    "YawSlot(double)\0VisibleSlot()\0"
    "unVisibleSlot()\0DestroySlot()\0"
    "NameSlot(int)\0"
};

const QMetaObject ParticleSetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ParticleSetWidget,
      qt_meta_data_ParticleSetWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ParticleSetWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ParticleSetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ParticleSetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ParticleSetWidget))
        return static_cast<void*>(const_cast< ParticleSetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ParticleSetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: UpdateParticle(); break;
        case 1: UpdateList(); break;
        case 2: SetSlot(); break;
        case 3: PosXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: PosYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: PosZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: ScaleXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: ScaleYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: ScaleZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: RollSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: PitchSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: YawSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: VisibleSlot(); break;
        case 13: unVisibleSlot(); break;
        case 14: DestroySlot(); break;
        case 15: NameSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void ParticleSetWidget::UpdateParticle()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
