/****************************************************************************
** Meta object code from reading C++ file 'buttonsconfiguration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ROV-Restructured/buttonsconfiguration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'buttonsconfiguration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_buttonsConfiguration_t {
    QByteArrayData data[9];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_buttonsConfiguration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_buttonsConfiguration_t qt_meta_stringdata_buttonsConfiguration = {
    {
QT_MOC_LITERAL(0, 0, 20), // "buttonsConfiguration"
QT_MOC_LITERAL(1, 21, 11), // "newSettings"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 6), // "config"
QT_MOC_LITERAL(4, 41, 12), // "timerClicked"
QT_MOC_LITERAL(5, 54, 13), // "cameraClicked"
QT_MOC_LITERAL(6, 68, 12), // "saveSettings"
QT_MOC_LITERAL(7, 81, 10), // "cancelEdit"
QT_MOC_LITERAL(8, 92, 9) // "show_hide"

    },
    "buttonsConfiguration\0newSettings\0\0"
    "config\0timerClicked\0cameraClicked\0"
    "saveSettings\0cancelEdit\0show_hide"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_buttonsConfiguration[] = {

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
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void buttonsConfiguration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        buttonsConfiguration *_t = static_cast<buttonsConfiguration *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newSettings((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->timerClicked(); break;
        case 2: _t->cameraClicked(); break;
        case 3: _t->saveSettings(); break;
        case 4: _t->cancelEdit(); break;
        case 5: _t->show_hide(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (buttonsConfiguration::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&buttonsConfiguration::newSettings)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject buttonsConfiguration::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_buttonsConfiguration.data,
      qt_meta_data_buttonsConfiguration,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *buttonsConfiguration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *buttonsConfiguration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_buttonsConfiguration.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int buttonsConfiguration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void buttonsConfiguration::newSettings(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE