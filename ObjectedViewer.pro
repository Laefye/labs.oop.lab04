QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    engine/edge.cpp \
    engine/facade.cpp \
    engine/figure.cpp \
    engine/filereader.cpp \
    engine/graphbuilder.cpp \
    engine/normalizationparameters.cpp \
    main.cpp \
    mainwindow.cpp \
    engine/matrix.cpp \
    engine/matrixbuilder.cpp \
    engine/point.cpp \
    qtscenedrawer.cpp \
    engine/scene.cpp \
    engine/vertex.cpp

HEADERS += \
    engine/basefilereader.h \
    engine/edge.h \
    engine/exceptions/filenotopenedexception.h \
    engine/exceptions/incorrectfileexception.h \
    engine/exceptions/incorrectindexexception.h \
    engine/exceptions/incorrectsize.h \
    engine/exceptions/scenenotloadedexception.h \
    engine/facade.h \
    engine/figure.h \
    engine/figurebuilder.h \
    engine/filereader.h \
    engine/graphbuilder.h \
    engine/normalizationparameters.h \
    mainwindow.h \
    engine/matrix.h \
    engine/matrixbuilder.h \
    engine/point.h \
    qtscenedrawer.h \
    engine/scene.h \
    engine/scenedrawerbase.h \
    engine/sceneobject.h \
    engine/vertex.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
