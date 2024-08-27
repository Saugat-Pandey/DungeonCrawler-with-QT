QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SetFloorTexture.cpp \
    abstractcontroller.cpp \
    active.cpp \
    attackcontroller.cpp \
    character.cpp \
    door.cpp \
    dungeoncrawler.cpp \
    floor.cpp \
    graph.cpp \
    graphicalui.cpp \
    guardiancontroller.cpp \
    level.cpp \
    levelchanger.cpp \
    lootchest.cpp \
    main.cpp \
    mainwindow.cpp \
    passive.cpp \
    pit.cpp \
    portal.cpp \
    ramp.cpp \
    random.cpp \
    startscreen.cpp \
    stationarycontroller.cpp \
    switch.cpp \
    tile.cpp \
    wall.cpp

HEADERS += \
    SetFloorTexture.h \
    abstractcontroller.h \
    active.h \
    attackcontroller.h \
    character.h \
    door.h \
    dungeoncrawler.h \
    floor.h \
    graph.h \
    graphicalui.h \
    guardiancontroller.h \
    level.h \
    levelchanger.h \
    list.h \
    lootchest.h \
    mainwindow.h \
    passive.h \
    pit.h \
    portal.h \
    ramp.h \
    random.h \
    startscreen.h \
    stationarycontroller.h \
    switch.h \
    tile.h \
    wall.h

FORMS += \
    mainwindow.ui \
    startscreen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    textures.qrc

DISTFILES +=
