/****************************************************************************
** Meta object code from reading C++ file 'GUITextSet.h'
**
** Created: Tue Aug 19 09:03:53 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUITextSet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUITextSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GUITextSetWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      30,   17,   17,   17, 0x0a,
      43,   17,   17,   17, 0x08,
      53,   17,   17,   17, 0x08,
      71,   17,   17,   17, 0x08,
      92,   17,   17,   17, 0x08,
     112,   17,   17,   17, 0x08,
     130,   17,   17,   17, 0x08,
     156,   17,   17,   17, 0x08,
     183,   17,   17,   17, 0x08,
     205,   17,   17,   17, 0x08,
     223,   17,   17,   17, 0x08,
     242,   17,   17,   17, 0x08,
     260,   17,   17,   17, 0x08,
     288,  282,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GUITextSetWidget[] = {
    "GUITextSetWidget\0\0UpdateGUI()\0"
    "UpdateList()\0SetSlot()\0FontSizeSlot(int)\0"
    "TextTopAlignedSlot()\0BottomAlignedSlot()\0"
    "VertCentredSlot()\0WordWrapLeftAlignedSlot()\0"
    "WordWrapRightAlignedSlot()\0"
    "WordWrapCentredSlot()\0LeftAlignedSlot()\0"
    "RightAlignedSlot()\0HorzCentredSlot()\0"
    "ClearPropertiesSlot()\0value\0NameSlot(int)\0"
};

const QMetaObject GUITextSetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GUITextSetWidget,
      qt_meta_data_GUITextSetWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GUITextSetWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GUITextSetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GUITextSetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GUITextSetWidget))
        return static_cast<void*>(const_cast< GUITextSetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int GUITextSetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: UpdateGUI(); break;
        case 1: UpdateList(); break;
        case 2: SetSlot(); break;
        case 3: FontSizeSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: TextTopAlignedSlot(); break;
        case 5: BottomAlignedSlot(); break;
        case 6: VertCentredSlot(); break;
        case 7: WordWrapLeftAlignedSlot(); break;
        case 8: WordWrapRightAlignedSlot(); break;
        case 9: WordWrapCentredSlot(); break;
        case 10: LeftAlignedSlot(); break;
        case 11: RightAlignedSlot(); break;
        case 12: HorzCentredSlot(); break;
        case 13: ClearPropertiesSlot(); break;
        case 14: NameSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
