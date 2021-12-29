QT       += core gui printsupport
#printsupport for notepad files
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    calculator.cpp \
    main.cpp \
    maindash.cpp \
    notepad.cpp \
    timer.cpp
#cpp files
HEADERS += \
    calculator.h \
    maindash.h \
    notepad.h \
    timer.h
#header files
FORMS += \
    calculator.ui \
    maindash.ui \
    notepad.ui \
    timer.ui
#GUIs
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
#resource files
