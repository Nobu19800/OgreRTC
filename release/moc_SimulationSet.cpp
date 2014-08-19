/****************************************************************************
** Meta object code from reading C++ file 'SimulationSet.h'
**
** Created: Tue Aug 19 09:02:59 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SimulationSet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SimulationSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SimulationSetWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x0a,
      34,   20,   20,   20, 0x08,
      52,   46,   20,   20, 0x08,
      72,   46,   20,   20, 0x08,
      88,   46,   20,   20, 0x08,
     104,   46,   20,   20, 0x08,
     121,   46,   20,   20, 0x08,
     138,   20,   20,   20, 0x08,
     151,   20,   20,   20, 0x08,
     162,   20,   20,   20, 0x08,
     174,   20,   20,   20, 0x08,
     188,   20,   20,   20, 0x08,
     199,   46,   20,   20, 0x08,
     215,   46,   20,   20, 0x08,
     233,   46,   20,   20, 0x08,
     255,   46,   20,   20, 0x08,
     274,   46,   20,   20, 0x08,
     293,   46,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SimulationSetWidget[] = {
    "SimulationSetWidget\0\0UpdateList()\0"
    "ResetSlot()\0value\0GravitySlot(double)\0"
    "CFMSlot(double)\0ERPSlot(double)\0"
    "gCFMSlot(double)\0gERPSlot(double)\0"
    "unQuiqSlot()\0QuiqSlot()\0StartSlot()\0"
    "RestartSlot()\0StopSlot()\0gMuSlot(double)\0"
    "STimeSlot(double)\0SleepTimeSlot(double)\0"
    "ScaleXSlot(double)\0ScaleYSlot(double)\0"
    "ScaleZSlot(double)\0"
};

const QMetaObject SimulationSetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SimulationSetWidget,
      qt_meta_data_SimulationSetWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SimulationSetWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SimulationSetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SimulationSetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SimulationSetWidget))
        return static_cast<void*>(const_cast< SimulationSetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SimulationSetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: UpdateList(); break;
        case 1: ResetSlot(); break;
        case 2: GravitySlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: CFMSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: ERPSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: gCFMSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: gERPSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: unQuiqSlot(); break;
        case 8: QuiqSlot(); break;
        case 9: StartSlot(); break;
        case 10: RestartSlot(); break;
        case 11: StopSlot(); break;
        case 12: gMuSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: STimeSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: SleepTimeSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: ScaleXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: ScaleYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: ScaleZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
