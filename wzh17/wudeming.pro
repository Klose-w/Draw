#-------------------------------------------------
#
# Project created by QtCreator 2016-07-05T08:14:32
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
qtHaveModule(printsupport): QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wudeming
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    paintarea.cpp \
    dodialog.cpp \
    Pen.cpp \
    cshape.cpp \
    diagram.cpp \
    operatethearea.cpp \
    music.cpp

HEADERS  += mainwindow.h \
    paintArea.h \
    paintarea.h \
    dodialog.h \
    Pen.h \
    cshape.h \
    diagram.h \
    operatethearea.h \
    music.h

FORMS    += mainwindow.ui \
    dodialog.ui

RC_FILE = icon.rc \

OTHER_FILES += \
    icon.rc\

RESOURCES += \
    resource.qrc\
