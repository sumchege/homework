/****************************************************************************
** Meta object code from reading C++ file 'qchannel_serial.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TaiComponents/qchannel_serial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qchannel_serial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QChannel_Serial_t {
    QByteArrayData data[17];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QChannel_Serial_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QChannel_Serial_t qt_meta_stringdata_QChannel_Serial = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QChannel_Serial"
QT_MOC_LITERAL(1, 16, 8), // "channels"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "open"
QT_MOC_LITERAL(4, 31, 4), // "name"
QT_MOC_LITERAL(5, 36, 5), // "close"
QT_MOC_LITERAL(6, 42, 6), // "isOpen"
QT_MOC_LITERAL(7, 49, 6), // "params"
QT_MOC_LITERAL(8, 56, 5), // "param"
QT_MOC_LITERAL(9, 62, 8), // "paramSet"
QT_MOC_LITERAL(10, 71, 5), // "value"
QT_MOC_LITERAL(11, 77, 9), // "readBytes"
QT_MOC_LITERAL(12, 87, 10), // "QList<int>"
QT_MOC_LITERAL(13, 98, 10), // "writeBytes"
QT_MOC_LITERAL(14, 109, 1), // "b"
QT_MOC_LITERAL(15, 111, 11), // "writeString"
QT_MOC_LITERAL(16, 123, 1) // "s"

    },
    "QChannel_Serial\0channels\0\0open\0name\0"
    "close\0isOpen\0params\0param\0paramSet\0"
    "value\0readBytes\0QList<int>\0writeBytes\0"
    "b\0writeString\0s"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QChannel_Serial[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x02 /* Public */,
       3,    1,   70,    2, 0x02 /* Public */,
       5,    0,   73,    2, 0x02 /* Public */,
       6,    0,   74,    2, 0x02 /* Public */,
       4,    0,   75,    2, 0x02 /* Public */,
       7,    0,   76,    2, 0x02 /* Public */,
       8,    1,   77,    2, 0x02 /* Public */,
       9,    2,   80,    2, 0x02 /* Public */,
      11,    0,   85,    2, 0x02 /* Public */,
      13,    1,   86,    2, 0x02 /* Public */,
      15,    1,   89,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::QStringList,
    QMetaType::Bool, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::QString,
    QMetaType::QStringList,
    QMetaType::QString, QMetaType::QString,    4,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,    4,   10,
    0x80000000 | 12,
    QMetaType::Bool, 0x80000000 | 12,   14,
    QMetaType::Bool, QMetaType::QString,   16,

       0        // eod
};

void QChannel_Serial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QChannel_Serial *_t = static_cast<QChannel_Serial *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QStringList _r = _t->channels();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->open((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: _t->close(); break;
        case 3: { bool _r = _t->isOpen();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { QString _r = _t->name();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { QStringList _r = _t->params();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 6: { QString _r = _t->param((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->paramSet((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { QList<int> _r = _t->readBytes();
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = _r; }  break;
        case 9: { bool _r = _t->writeBytes((*reinterpret_cast< const QList<int>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { bool _r = _t->writeString((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        }
    }
}

const QMetaObject QChannel_Serial::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QChannel_Serial.data,
      qt_meta_data_QChannel_Serial,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QChannel_Serial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QChannel_Serial::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QChannel_Serial.stringdata0))
        return static_cast<void*>(const_cast< QChannel_Serial*>(this));
    return QObject::qt_metacast(_clname);
}

int QChannel_Serial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
