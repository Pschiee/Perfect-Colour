
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AppPerfectColourDemo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += qt warn_on_debug

SOURCES += sources/main.cpp sources/mainwindow.cpp sources/selectcolour.cpp sources/myThread.cpp sources/weight.cpp sources/paint.cpp sources/Motor.cpp sources/chosen_colour.cpp sources/HX711.cpp sources/my_qlabel.cpp sources/dc_motor.cpp sources/cleanpaint.cpp

HEADERS += includes/mainwindow.h includes/selectcolour.h includes/myThread.h includes/paint.h includes/Motor.h includes/chosen_colour.h includes/HX711.h includes/my_qlabel.h includes/cleanpaint.h \
    includes/dc_motor.h includes/weight.h includes/CppThread.h \
    includes/dc_motor.h

FORMS += ui_files/mainwindow.ui ui_files/selectcolour.ui ui_files/paint.ui ui_files/cleanpaint.ui

OBJECTS_DIR = bin
MOC_DIR=generated_files
UI_DIR = bin/.ui
O_DIR = bin/.o
#Debug:DESTDIR = bin
#Debug:OBJECTS_DIR = bin/.obj
#Debug:MOC_DIR = bin/.moc
#Debug:RCC_DIR= bin/.rcc
#Debug:UI_DIR = bin/.ui
#Debug:O_DIR = bin/.o

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += resources.qrc

INCLUDEPATH	+= /usr/local/include

LIBS += -L/usr/local/lib -lwiringPi
