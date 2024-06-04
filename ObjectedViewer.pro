QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    edge.cpp \
    facade.cpp \
    figure.cpp \
    filereader.cpp \
    graphbuilder.cpp \
    normalizationparameters.cpp \
    main.cpp \
    mainwindow.cpp \
    matrix.cpp \
    matrixbuilder.cpp \
    point.cpp \
    qtscenedrawer.cpp \
    scene.cpp \
    vertex.cpp

HEADERS += \
    basefilereader.h \
    edge.h \
    exceptions/filenotopenedexception.h \
    exceptions/incorrectfileexception.h \
    exceptions/incorrectindexexception.h \
    exceptions/incorrectsize.h \
    exceptions/scenenotloadedexception.h \
    facade.h \
    figure.h \
    figurebuilder.h \
    filereader.h \
    graphbuilder.h \
    normalizationparameters.h \
    mainwindow.h \
    matrix.h \
    matrixbuilder.h \
    point.h \
    qtscenedrawer.h \
    scene.h \
    scenedrawerbase.h \
    sceneobject.h \
    vertex.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
