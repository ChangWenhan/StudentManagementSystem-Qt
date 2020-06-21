#-------------------------------------------------
#
# Project created by QtCreator 2019-07-22T10:12:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudentManagementSystemCWH
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

CONFIG += c++11

SOURCES += \
        addmodule.cpp \
        addstudent.cpp \
        course_delete.cpp \
        course_inquire.cpp \
        course_select.cpp \
        deletemodule.cpp \
        madds.cpp \
        main.cpp \
        mainwindow.cpp \
        managerfunc.cpp \
        managermenu.cpp \
        mdelete.cpp \
        menu.cpp \
        modifystudent.cpp \
        selectstudent.cpp \
        sortstudent.cpp \
        studentfunc.cpp \
        teacherfunc.cpp \
        teachermenu.cpp

HEADERS += \
        addmodule.h \
        addstudent.h \
        course_delete.h \
        course_inquire.h \
        course_select.h \
        deletemodule.h \
        madds.h \
        mainwindow.h \
        managerfunc.h \
        managermenu.h \
        mdelete.h \
        menu.h \
        modifystudent.h \
        selectstudent.h \
        sortstudent.h \
        studentfunc.h \
        teacherfunc.h \
        teachermenu.h

FORMS += \
        addmodule.ui \
        addstudent.ui \
        course_delete.ui \
        course_inquire.ui \
        course_select.ui \
        deletemodule.ui \
        madds.ui \
        mainwindow.ui \
        managerfunc.ui \
        managermenu.ui \
        mdelete.ui \
        menu.ui \
        modifystudent.ui \
        selectstudent.ui \
        sortstudent.ui \
        studentfunc.ui \
        teacherfunc.ui \
        teachermenu.ui
QT += widgets
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    C:/Users/christan/Desktop/cug_picture/cug_pic.qrc \
    C:/Users/christan/Desktop/cug_picture/pic.qrc
