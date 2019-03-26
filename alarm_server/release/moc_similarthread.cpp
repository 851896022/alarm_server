/****************************************************************************
** Meta object code from reading C++ file 'similarthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../alarm/similarthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'similarthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SimilarThread_t {
    QByteArrayData data[6];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SimilarThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SimilarThread_t qt_meta_stringdata_SimilarThread = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SimilarThread"
QT_MOC_LITERAL(1, 14, 14), // "sendSimilarity"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 2), // "ch"
QT_MOC_LITERAL(4, 33, 1), // "N"
QT_MOC_LITERAL(5, 35, 10) // "workFinish"

    },
    "SimilarThread\0sendSimilarity\0\0ch\0N\0"
    "workFinish"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimilarThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       5,    0,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Float,    3,    4,
    QMetaType::Void,

       0        // eod
};

void SimilarThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SimilarThread *_t = static_cast<SimilarThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendSimilarity((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 1: _t->workFinish(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SimilarThread::*_t)(int , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimilarThread::sendSimilarity)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SimilarThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimilarThread::workFinish)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SimilarThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_SimilarThread.data,
      qt_meta_data_SimilarThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SimilarThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimilarThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SimilarThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int SimilarThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void SimilarThread::sendSimilarity(int _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SimilarThread::workFinish()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
