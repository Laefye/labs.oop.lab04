QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    filereader.cpp \
    normalizationparameters.cpp \
    main.cpp \
    mainwindow.cpp \
    matrix.cpp \
    matrixbuilder.cpp \
    point.cpp \
    scene.cpp

HEADERS += \
    basefilereader.h \
    exceptions/incorrectfileexception.h \
    exceptions/incorrectindexexception.h \
    exceptions/incorrectsize.h \
    filereader.h \
    normalizationparameters.h \
    mainwindow.h \
    matrix.h \
    matrixbuilder.h \
    point.h \
    scene.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
