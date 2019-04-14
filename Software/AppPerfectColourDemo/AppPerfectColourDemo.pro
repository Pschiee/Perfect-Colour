#-------------------------------------------------
#
# Project created by QtCreator 2019-02-27T10:31:06
#
#-------------------------------------------------

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

SOURCES += main.cpp mainwindow.cpp myThread.cpp selectcolour.cpp weight.cpp paint.cpp Motor.cpp dispense.cpp chosen_colour.cpp HX711.cpp my_qlabel.cpp dc_motor.cpp cleanpaint.cpp

HEADERS += mainwindow.h selectcolour.h paint.h myThread.h Motor.h dispense.h chosen_colour.h HX711.h my_qlabel.h cleanpaint.h \
    dc_motor.h weight.h \
    dc_motor.h

FORMS += mainwindow.ui selectcolour.ui paint.ui cleanpaint.ui
    

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += resources.qrc

INCLUDEPATH	+= /usr/local/include

LIBS += -L/usr/local/lib -lwiringPi
