/****************************************************************************
** Meta object code from reading C++ file 'alarmsimilar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../alarm/alarmsimilar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'alarmsimilar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ALarmSimilar_t {
    QByteArrayData data[7];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ALarmSimilar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ALarmSimilar_t qt_meta_stringdata_ALarmSimilar = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ALarmSimilar"
QT_MOC_LITERAL(1, 13, 5), // "alert"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7), // "simInfo"
QT_MOC_LITERAL(4, 28, 8), // "initThis"
QT_MOC_LITERAL(5, 37, 6), // "doWork"
QT_MOC_LITERAL(6, 44, 7) // "doAlert"

    },
    "ALarmSimilar\0alert\0\0simInfo\0initThis\0"
    "doWork\0doAlert"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ALarmSimilar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       1,    3,   47,    2, 0x06 /* Public */,
       3,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   59,    2, 0x0a /* Public */,
       5,    0,   60,    2, 0x0a /* Public */,
       6,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QDateTime,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Float,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ALarmSimilar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ALarmSimilar *_t = static_cast<ALarmSimilar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->alert((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->alert((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QDateTime(*)>(_a[3]))); break;
        case 2: _t->simInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 3: _t->initThis(); break;
        case 4: _t->doWork(); break;
        case 5: _t->doAlert(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ALarmSimilar::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ALarmSimilar::alert)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ALarmSimilar::*_t)(int , int , QDateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ALarmSimilar::alert)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ALarmSimilar::*_t)(int , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ALarmSimilar::simInfo)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ALarmSimilar::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ALarmSimilar.data,
      qt_meta_data_ALarmSimilar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ALarmSimilar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ALarmSimilar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ALarmSimilar.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ALarmSimilar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void ALarmSimilar::alert(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ALarmSimilar::alert(int _t1, int _t2, QDateTime _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ALarmSimilar::simInfo(int _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
