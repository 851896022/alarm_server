/****************************************************************************
** Meta object code from reading C++ file 'alarmapm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../alarm_server/alarm/alarmapm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'alarmapm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AlarmApm_t {
    QByteArrayData data[6];
    char stringdata0[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AlarmApm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AlarmApm_t qt_meta_stringdata_AlarmApm = {
    {
QT_MOC_LITERAL(0, 0, 8), // "AlarmApm"
QT_MOC_LITERAL(1, 9, 5), // "alert"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 8), // "initThis"
QT_MOC_LITERAL(4, 25, 6), // "doTest"
QT_MOC_LITERAL(5, 32, 7) // "doAlert"

    },
    "AlarmApm\0alert\0\0initThis\0doTest\0doAlert"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AlarmApm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       1,    3,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   49,    2, 0x0a /* Public */,
       4,    0,   50,    2, 0x08 /* Private */,
       5,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QDateTime,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AlarmApm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AlarmApm *_t = static_cast<AlarmApm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->alert((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->alert((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QDateTime(*)>(_a[3]))); break;
        case 2: _t->initThis(); break;
        case 3: _t->doTest(); break;
        case 4: _t->doAlert(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AlarmApm::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AlarmApm::alert)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AlarmApm::*_t)(int , int , QDateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AlarmApm::alert)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject AlarmApm::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AlarmApm.data,
      qt_meta_data_AlarmApm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AlarmApm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AlarmApm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AlarmApm.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AlarmApm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void AlarmApm::alert(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AlarmApm::alert(int _t1, int _t2, QDateTime _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
