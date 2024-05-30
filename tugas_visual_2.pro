QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cadangan.cpp \
    formcadangan.cpp \
    formiup.cpp \
    formkapal.cpp \
    formrealisasi.cpp \
    formuser.cpp \
    formwilayah.cpp \
    iup.cpp \
    kapal.cpp \
    main.cpp \
    mainwindow.cpp \
    realisasi.cpp \
    user.cpp \
    wilayah.cpp

HEADERS += \
    cadangan.h \
    formcadangan.h \
    formiup.h \
    formkapal.h \
    formrealisasi.h \
    formuser.h \
    formwilayah.h \
    iup.h \
    kapal.h \
    mainwindow.h \
    realisasi.h \
    user.h \
    wilayah.h

FORMS += \
    formcadangan.ui \
    formiup.ui \
    formkapal.ui \
    formrealisasi.ui \
    formuser.ui \
    formwilayah.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
