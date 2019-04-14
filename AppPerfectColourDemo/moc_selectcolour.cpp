/****************************************************************************
** Meta object code from reading C++ file 'selectcolour.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "selectcolour.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectcolour.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_selectcolour_t {
    QByteArrayData data[9];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_selectcolour_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_selectcolour_t qt_meta_stringdata_selectcolour = {
    {
QT_MOC_LITERAL(0, 0, 12), // "selectcolour"
QT_MOC_LITERAL(1, 13, 4), // "send"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 6), // "Colour"
QT_MOC_LITERAL(4, 26, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 48, 18), // "on_Confirm_clicked"
QT_MOC_LITERAL(6, 67, 17), // "Mouse_current_pos"
QT_MOC_LITERAL(7, 85, 13), // "Mouse_Pressed"
QT_MOC_LITERAL(8, 99, 10) // "Mouse_left"

    },
    "selectcolour\0send\0\0Colour\0"
    "on_pushButton_clicked\0on_Confirm_clicked\0"
    "Mouse_current_pos\0Mouse_Pressed\0"
    "Mouse_left"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_selectcolour[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   47,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void selectcolour::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        selectcolour *_t = static_cast<selectcolour *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_Confirm_clicked(); break;
        case 3: _t->Mouse_current_pos(); break;
        case 4: _t->Mouse_Pressed(); break;
        case 5: _t->Mouse_left(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (selectcolour::*_t)(QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&selectcolour::send)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject selectcolour::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_selectcolour.data,
      qt_meta_data_selectcolour,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *selectcolour::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *selectcolour::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_selectcolour.stringdata0))
        return static_cast<void*>(const_cast< selectcolour*>(this));
    return QDialog::qt_metacast(_clname);
}

int selectcolour::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void selectcolour::send(QColor _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
