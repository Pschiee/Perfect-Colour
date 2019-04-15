/****************************************************************************
** Meta object code from reading C++ file 'paint.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../includes/paint.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paint.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_paint_t {
    QByteArrayData data[10];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_paint_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_paint_t qt_meta_stringdata_paint = {
    {
QT_MOC_LITERAL(0, 0, 5), // "paint"
QT_MOC_LITERAL(1, 6, 8), // "received"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 21), // "on_white_stateChanged"
QT_MOC_LITERAL(4, 38, 4), // "arg1"
QT_MOC_LITERAL(5, 43, 20), // "on_cyan_stateChanged"
QT_MOC_LITERAL(6, 64, 23), // "on_magenta_stateChanged"
QT_MOC_LITERAL(7, 88, 22), // "on_yellow_stateChanged"
QT_MOC_LITERAL(8, 111, 21), // "on_black_stateChanged"
QT_MOC_LITERAL(9, 133, 16) // "on_start_clicked"

    },
    "paint\0received\0\0on_white_stateChanged\0"
    "arg1\0on_cyan_stateChanged\0"
    "on_magenta_stateChanged\0on_yellow_stateChanged\0"
    "on_black_stateChanged\0on_start_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_paint[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x0a /* Public */,
       3,    1,   54,    2, 0x08 /* Private */,
       5,    1,   57,    2, 0x08 /* Private */,
       6,    1,   60,    2, 0x08 /* Private */,
       7,    1,   63,    2, 0x08 /* Private */,
       8,    1,   66,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QColor, QMetaType::Double,    2,    2,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,

       0        // eod
};

void paint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        paint *_t = static_cast<paint *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->received((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->on_white_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_cyan_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_magenta_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_yellow_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_black_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_start_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject paint::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_paint.data,
      qt_meta_data_paint,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *paint::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *paint::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_paint.stringdata0))
        return static_cast<void*>(const_cast< paint*>(this));
    return QDialog::qt_metacast(_clname);
}

int paint::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
