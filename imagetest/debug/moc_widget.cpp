/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widget.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSWidgetENDCLASS = QtMocHelpers::stringData(
    "Widget",
    "beginWork",
    "",
    "img",
    "QThread*",
    "workerThread",
    "takepicture",
    "showpicture",
    "id",
    "preview",
    "tokenReply",
    "QNetworkReply*",
    "reply",
    "imageRequery",
    "postData",
    "imageReply",
    "readyImage",
    "cameraChange",
    "index",
    "beginGame",
    "analyGame"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSWidgetENDCLASS_t {
    uint offsetsAndSizes[42];
    char stringdata0[7];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[9];
    char stringdata5[13];
    char stringdata6[12];
    char stringdata7[12];
    char stringdata8[3];
    char stringdata9[8];
    char stringdata10[11];
    char stringdata11[15];
    char stringdata12[6];
    char stringdata13[13];
    char stringdata14[9];
    char stringdata15[11];
    char stringdata16[11];
    char stringdata17[13];
    char stringdata18[6];
    char stringdata19[10];
    char stringdata20[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSWidgetENDCLASS_t qt_meta_stringdata_CLASSWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Widget"
        QT_MOC_LITERAL(7, 9),  // "beginWork"
        QT_MOC_LITERAL(17, 0),  // ""
        QT_MOC_LITERAL(18, 3),  // "img"
        QT_MOC_LITERAL(22, 8),  // "QThread*"
        QT_MOC_LITERAL(31, 12),  // "workerThread"
        QT_MOC_LITERAL(44, 11),  // "takepicture"
        QT_MOC_LITERAL(56, 11),  // "showpicture"
        QT_MOC_LITERAL(68, 2),  // "id"
        QT_MOC_LITERAL(71, 7),  // "preview"
        QT_MOC_LITERAL(79, 10),  // "tokenReply"
        QT_MOC_LITERAL(90, 14),  // "QNetworkReply*"
        QT_MOC_LITERAL(105, 5),  // "reply"
        QT_MOC_LITERAL(111, 12),  // "imageRequery"
        QT_MOC_LITERAL(124, 8),  // "postData"
        QT_MOC_LITERAL(133, 10),  // "imageReply"
        QT_MOC_LITERAL(144, 10),  // "readyImage"
        QT_MOC_LITERAL(155, 12),  // "cameraChange"
        QT_MOC_LITERAL(168, 5),  // "index"
        QT_MOC_LITERAL(174, 9),  // "beginGame"
        QT_MOC_LITERAL(184, 9)   // "analyGame"
    },
    "Widget",
    "beginWork",
    "",
    "img",
    "QThread*",
    "workerThread",
    "takepicture",
    "showpicture",
    "id",
    "preview",
    "tokenReply",
    "QNetworkReply*",
    "reply",
    "imageRequery",
    "postData",
    "imageReply",
    "readyImage",
    "cameraChange",
    "index",
    "beginGame",
    "analyGame"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   74,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   79,    2, 0x0a,    4 /* Public */,
       7,    2,   80,    2, 0x0a,    5 /* Public */,
      10,    1,   85,    2, 0x0a,    8 /* Public */,
      13,    2,   88,    2, 0x0a,   10 /* Public */,
      15,    1,   93,    2, 0x0a,   13 /* Public */,
      16,    0,   96,    2, 0x0a,   15 /* Public */,
      17,    1,   97,    2, 0x0a,   16 /* Public */,
      19,    0,  100,    2, 0x0a,   18 /* Public */,
      20,    0,  101,    2, 0x0a,   19 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QImage,    8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 4,   14,    5,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Widget, std::true_type>,
        // method 'beginWork'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        QtPrivate::TypeAndForceComplete<QThread *, std::false_type>,
        // method 'takepicture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showpicture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        // method 'tokenReply'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'imageRequery'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        QtPrivate::TypeAndForceComplete<QThread *, std::false_type>,
        // method 'imageReply'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'readyImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cameraChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'beginGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'analyGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->beginWork((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QThread*>>(_a[2]))); break;
        case 1: _t->takepicture(); break;
        case 2: _t->showpicture((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QImage>>(_a[2]))); break;
        case 3: _t->tokenReply((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 4: _t->imageRequery((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QThread*>>(_a[2]))); break;
        case 5: _t->imageReply((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 6: _t->readyImage(); break;
        case 7: _t->cameraChange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->beginGame(); break;
        case 9: _t->analyGame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QThread* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QThread* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Widget::*)(QImage , QThread * );
            if (_t _q_method = &Widget::beginWork; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Widget::beginWork(QImage _t1, QThread * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
