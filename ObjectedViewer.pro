QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    engine/scene/edge.cpp \
    engine/facade.cpp \
    engine/scene/figure.cpp \
    engine/filereader.cpp \
    engine/scene/graphbuilder.cpp \
    engine/normalizationparameters.cpp \
    engine/scene/orthogonal.cpp \
    engine/scene/perspective.cpp \
    engine/scene/scenedrawerbase.cpp \
    main.cpp \
    mainwindow.cpp \
    engine/math/matrix.cpp \
    engine/math/matrixbuilder.cpp \
    engine/math/point.cpp \
    normalizationdialog.cpp \
    qtscenedrawer.cpp \
    engine/scene/scene.cpp \
    engine/scene/vertex.cpp

HEADERS += \
    engine/basefilereader.h \
    engine/scene/edge.h \
    engine/exceptions/filenotopenedexception.h \
    engine/exceptions/incorrectfileexception.h \
    engine/exceptions/incorrectindexexception.h \
    engine/exceptions/incorrectsize.h \
    engine/exceptions/scenenotloadedexception.h \
    engine/facade.h \
    engine/scene/figure.h \
    engine/scene/figurebuilder.h \
    engine/filereader.h \
    engine/scene/graphbuilder.h \
    engine/normalizationparameters.h \
    engine/scene/orthogonal.h \
    engine/scene/perspective.h \
    engine/scene/projection.h \
    mainwindow.h \
    engine/math/matrix.h \
    engine/math/matrixbuilder.h \
    engine/math/point.h \
    normalizationdialog.h \
    qtscenedrawer.h \
    engine/scene/scene.h \
    engine/scene/scenedrawerbase.h \
    engine/scene/sceneobject.h \
    engine/scene/vertex.h

FORMS += \
    mainwindow.ui \
    normalizationdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
