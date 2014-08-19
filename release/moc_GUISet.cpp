/****************************************************************************
** Meta object code from reading C++ file 'GUISet.h'
**
** Created: Tue Aug 19 09:03:58 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUISet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUISet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GUISetWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      26,   13,   13,   13, 0x0a,
      39,   13,   13,   13, 0x08,
      55,   49,   13,   13, 0x08,
      72,   49,   13,   13, 0x08,
      89,   49,   13,   13, 0x08,
     106,   49,   13,   13, 0x08,
     124,   49,   13,   13, 0x08,
     140,   49,   13,   13, 0x08,
     159,   49,   13,   13, 0x08,
     178,   49,   13,   13, 0x08,
     196,   13,   13,   13, 0x08,
     210,   13,   13,   13, 0x08,
     226,   13,   13,   13, 0x08,
     238,   13,   13,   13, 0x08,
     252,   13,   13,   13, 0x08,
     269,   13,   13,   13, 0x08,
     288,   13,   13,   13, 0x08,
     302,   49,   13,   13, 0x08,
     316,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GUISetWidget[] = {
    "GUISetWidget\0\0UpdateGUI()\0UpdateList()\0"
    "SetSlot()\0value\0PosXSlot(double)\0"
    "PosYSlot(double)\0RollSlot(double)\0"
    "PitchSlot(double)\0YawSlot(double)\0"
    "ScaleXSlot(double)\0ScaleYSlot(double)\0"
    "AlphaSlot(double)\0VisibleSlot()\0"
    "unVisibleSlot()\0FrameSlot()\0unFrameSlot()\0"
    "BackGroundSlot()\0unBackGroundSlot()\0"
    "DestroySlot()\0NameSlot(int)\0WindowSlot()\0"
};

const QMetaObject GUISetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GUISetWidget,
      qt_meta_data_GUISetWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GUISetWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GUISetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GUISetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GUISetWidget))
        return static_cast<void*>(const_cast< GUISetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int GUISetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: UpdateGUI(); break;
        case 1: UpdateList(); break;
        case 2: SetSlot(); break;
        case 3: PosXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: PosYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: RollSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: PitchSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: YawSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: ScaleXSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: ScaleYSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: AlphaSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: VisibleSlot(); break;
        case 12: unVisibleSlot(); break;
        case 13: FrameSlot(); break;
        case 14: unFrameSlot(); break;
        case 15: BackGroundSlot(); break;
        case 16: unBackGroundSlot(); break;
        case 17: DestroySlot(); break;
        case 18: NameSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: WindowSlot(); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void GUISetWidget::UpdateGUI()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
