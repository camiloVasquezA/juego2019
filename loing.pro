    #-------------------------------------------------
#
# Project created by QtCreator 2018-12-06T14:54:17
#
#-------------------------------------------------
QT       += core gui widgets serialport
QT       += core gui widgets sql
QT       += core gui serialport
QT       += core gui \
          multimedia


TARGET = loing
TEMPLATE = app
include($$PWD/Botan.pri)

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += resources_big

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    DuCrypt.cpp \
    botan.cpp \
    dialog.cpp \
    administrador.cpp \
    usuario.cpp \
    mainwindow_juego.cpp \
    arkanoid.cpp \
    vidas.cpp \
    timer.cpp \
    platafor_item.cpp \
    objecitem.cpp \
    my_scena.cpp \
    d_util.cpp \
    ball_item.cpp \
    bloque.cpp \
    multijugador.cpp \
    niveles.cpp \
    my_scena2.cpp \
    my_scena3.cpp \
    my_scena4.cpp \
    mariaf.cpp

HEADERS += \
        mainwindow.h \
    DuCrypt.h \
    botan.h \
    dialog.h \
    administrador.h \
    usuario.h \
    mainwindow_juego.h \
    arkanoid.h \
    vidas.h \
    timer.h \
    platafor_item.h \
    objecitem.h \
    my_scena.h \
    d_util.h \
    global_defines.h \
    ball_item.h \
    bloque.h \
    multijugador.h \
    niveles.h \
    my_scena2.h \
    my_scena3.h \
    my_scena4.h \
    mariaf.h

FORMS += \
        mainwindow.ui \
    dialog.ui \
    mainwindow_juego.ui \
    niveles.ui

QMAKE_CXXFLAGS += -std=gnu++14

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagen.qrc

DISTFILES += \
    C:/Users/Camilo/Desktop/INSTRUMENTO PARA RECOLECTAR INFORMACIÓN.doc \
    C:/Users/Camilo/Desktop/COMUNICADO OFICIAL COMCUERDAS.pdf \
    C:/Program Files (x86)/Dev-Cpp/devcpp.exe \
    Rebote pelota 2D-[AudioTrimmer.com].mp3

