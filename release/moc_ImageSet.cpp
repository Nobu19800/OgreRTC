/****************************************************************************
** Meta object code from reading C++ file 'ImageSet.h'
**
** Created: Sun Feb 9 23:51:33 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ImageSet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageSetWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      29,   15,   15,   15, 0x0a,
      41,   15,   15,   15, 0x08,
      51,   15,   15,   15, 0x08,
      71,   65,   15,   15, 0x08,
      85,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ImageSetWidget[] = {
    "ImageSetWidget\0\0UpdateList()\0UpdateGUI()\0"
    "SetSlot()\0DestroySlot()\0value\0"
    "NameSlot(int)\0SetGUISlot()\0"
};

const QMetaObject ImageSetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ImageSetWidget,
      qt_meta_data_ImageSetWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageSetWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageSetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageSetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageSetWidget))
        return static_cast<void*>(const_cast< ImageSetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ImageSetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: UpdateList(); break;
        case 1: UpdateGUI(); break;
        case 2: SetSlot(); break;
        case 3: DestroySlot(); break;
        case 4: NameSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: SetGUISlot(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
