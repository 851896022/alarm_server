/****************************************************************************
** Meta object code from reading C++ file 'senddata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../alarm_server/alarm/senddata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'senddata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SendData_t {
    QByteArrayData data[9];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SendData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SendData_t qt_meta_stringdata_SendData = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SendData"
QT_MOC_LITERAL(1, 9, 8), // "initThis"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "onAlert"
QT_MOC_LITERAL(4, 27, 2), // "ch"
QT_MOC_LITERAL(5, 30, 4), // "type"
QT_MOC_LITERAL(6, 35, 4), // "time"
QT_MOC_LITERAL(7, 40, 7), // "simData"
QT_MOC_LITERAL(8, 48, 3) // "sim"

    },
    "SendData\0initThis\0\0onAlert\0ch\0type\0"
    "time\0simData\0sim"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SendData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       3,    3,   38,    2, 0x0a /* Public */,
       7,    2,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QDateTime,    4,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Float,    4,    8,

       0        // eod
};

void SendData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SendData *_t = static_cast<SendData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initThis(); break;
        case 1: _t->onAlert((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onAlert((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QDateTime(*)>(_a[3]))); break;
        case 3: _t->simData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject SendData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SendData.data,
      qt_meta_data_SendData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SendData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SendData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SendData.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SendData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
