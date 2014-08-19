/****************************************************************************
** Meta object code from reading C++ file 'CameraSet.h'
**
** Created: Tue Aug 19 09:04:05 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CameraSet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CameraSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CameraSetWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      40,   30,   16,   16, 0x0a,
      80,   76,   16,   16, 0x0a,
     109,   76,   16,   16, 0x0a,
     146,  140,   16,   16, 0x08,
     165,  140,   16,   16, 0x08,
     184,  140,   16,   16, 0x08,
     203,  140,   16,   16, 0x08,
     223,  140,   16,   16, 0x08,
     243,  140,   16,   16, 0x08,
     263,  140,   16,   16, 0x08,
     280,  140,   16,   16, 0x08,
     297,  140,   16,   16, 0x08,
     314,  140,   16,   16, 0x08,
     331,  140,   16,   16, 0x08,
     349,  140,   16,   16, 0x08,
     365,  140,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CameraSetWidget[] = {
    "CameraSetWidget\0\0UpdateList()\0evt,dx,dy\0"
    "mouseMoveSlot(QMouseEvent*,int,int)\0"
    "evt\0mousePressSlot(QMouseEvent*)\0"
    "mouseReleaseSlot(QMouseEvent*)\0value\0"
    "LightXSlot(double)\0LightYSlot(double)\0"
    "LightZSlot(double)\0ShadowRSlot(double)\0"
    "ShadowGSlot(double)\0ShadowBSlot(double)\0"
    "PosXSlot(double)\0PosYSlot(double)\0"
    "PosZSlot(double)\0RollSlot(double)\0"
    "PitchSlot(double)\0YawSlot(double)\0"
    "LenSlot(double)\0"
};

const QMetaObject CameraSetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CameraSetWidget,
      qt_meta_data_CameraSetWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CameraSetWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CameraSetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CameraSetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CameraSetWidget))
        return static_cast<void*>(const_cast< CameraSetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CameraSetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: UpdateList(); break;
        case 1: mouseMoveSlot((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: mousePressSlot((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: mouseReleaseSlot((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: LightXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: LightYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: LightZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: ShadowRSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: ShadowGSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: ShadowBSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: PosXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: PosYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: PosZSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: RollSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: PitchSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: YawSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: LenSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
