/****************************************************************************
** Meta object code from reading C++ file 'global.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../alarm_server/global.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'global.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Global_t {
    QByteArrayData data[10];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Global_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Global_t qt_meta_stringdata_Global = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Global"
QT_MOC_LITERAL(1, 7, 11), // "outPutState"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7), // "refTime"
QT_MOC_LITERAL(4, 28, 10), // "getNowFreq"
QT_MOC_LITERAL(5, 39, 13), // "transmitterNo"
QT_MOC_LITERAL(6, 53, 12), // "addAlarmInfo"
QT_MOC_LITERAL(7, 66, 2), // "ch"
QT_MOC_LITERAL(8, 69, 9), // "AlarmType"
QT_MOC_LITERAL(9, 79, 9) // "alarmType"

    },
    "Global\0outPutState\0\0refTime\0getNowFreq\0"
    "transmitterNo\0addAlarmInfo\0ch\0AlarmType\0"
    "alarmType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Global[] = {

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
       3,    0,   35,    2, 0x0a /* Public */,
       4,    1,   36,    2, 0x0a /* Public */,
       6,    2,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int,    5,
    QMetaType::Int, QMetaType::Int, 0x80000000 | 8,    7,    9,

       0        // eod
};

void Global::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Global *_t = static_cast<Global *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->outPutState(); break;
        case 1: _t->refTime(); break;
        case 2: { int _r = _t->getNowFreq((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->addAlarmInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< AlarmType(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject Global::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Global.data,
      qt_meta_data_Global,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Global::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Global::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Global.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Global::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
