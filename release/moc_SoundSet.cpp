/****************************************************************************
** Meta object code from reading C++ file 'SoundSet.h'
**
** Created: Wed Feb 5 02:12:57 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SoundSet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SoundSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SoundSetWidget[] = {

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
      16,   15,   15,   15, 0x08,
      32,   26,   15,   15, 0x08,
      57,   26,   15,   15, 0x08,
      75,   26,   15,   15, 0x08,
      94,   15,   15,   15, 0x08,
     112,   15,   15,   15, 0x08,
     132,   26,   15,   15, 0x08,
     153,   15,   15,   15, 0x08,
     164,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SoundSetWidget[] = {
    "SoundSetWidget\0\0SetSlot()\0value\0"
    "EngineVolumeSlot(double)\0SpeedSlot(double)\0"
    "VolumeSlot(double)\0VolumePauseSlot()\0"
    "VolumeunPauseSlot()\0PositionSlot(double)\0"
    "StopSlot()\0ResetSlot()\0"
};

const QMetaObject SoundSetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SoundSetWidget,
      qt_meta_data_SoundSetWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SoundSetWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SoundSetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SoundSetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SoundSetWidget))
        return static_cast<void*>(const_cast< SoundSetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SoundSetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: SetSlot(); break;
        case 1: EngineVolumeSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: SpeedSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: VolumeSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: VolumePauseSlot(); break;
        case 5: VolumeunPauseSlot(); break;
        case 6: PositionSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: StopSlot(); break;
        case 8: ResetSlot(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
