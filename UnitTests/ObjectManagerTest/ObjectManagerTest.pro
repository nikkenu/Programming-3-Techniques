QT += testlib
QT += core gui widgets

CONFIG += qt console warn_on depend_includepath testcase c++14
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += \
    $$PWD/../../Course/CourseLib \
    $$PWD/../../Game

DEPENDPATH += \
    $$PWD/../../Course/CourseLib \
    $$PWD/../../Game

HEADERS += \
    ../../Game/farmer.h \
    ../../Game/gameeventhandler.h \
    ../../Game/gamescene.h \
    ../../Game/mine.h \
    ../../Game/miner.h \
    ../../Game/oilrig.h \
    ../../Game/player.h \
    ../../Course/CourseLib/buildings/buildingbase.h \
    ../../Course/CourseLib/buildings/farm.h \
    ../../Course/CourseLib/buildings/headquarters.h \
    ../../Course/CourseLib/buildings/outpost.h \
    ../../Course/CourseLib/core/basicresources.h \
    ../../Course/CourseLib/core/placeablegameobject.h \
    ../../Course/CourseLib/interfaces/iobjectmanager.h \
    ../../Course/CourseLib/tiles/tilebase.h \
    ../../Course/CourseLib/workers/basicworker.h \
    ../../Course/CourseLib/workers/workerbase.h \
    ../../Course/CourseLib/core/gameobject.h \
    ../../Course/CourseLib/core/playerbase.h \
    ../../Game/mapitem.h \
    ../../Game/staticstorage.h \
    ../../Course/CourseLib/core/coordinate.h \
    ../../Game/objectmanager.h \
    ../../Course/CourseLib/core/worldgenerator.h \
    ../../Game/studentresourcemaps.h \
    ../../Course/CourseLib/tiles/forest.h

SOURCES +=  tst_objectmanagertest.cpp \
    ../../Game/farmer.cpp \
    ../../Game/gameeventhandler.cpp \
    ../../Game/gamescene.cpp \
    ../../Game/mine.cpp \
    ../../Game/miner.cpp \
    ../../Game/oilrig.cpp \
    ../../Game/player.cpp \
    ../../Course/CourseLib/buildings/buildingbase.cpp \
    ../../Course/CourseLib/buildings/farm.cpp \
    ../../Course/CourseLib/buildings/headquarters.cpp \
    ../../Course/CourseLib/buildings/outpost.cpp \
    ../../Course/CourseLib/core/basicresources.cpp \
    ../../Course/CourseLib/core/placeablegameobject.cpp \
    ../../Course/CourseLib/tiles/tilebase.cpp \
    ../../Course/CourseLib/workers/basicworker.cpp \
    ../../Course/CourseLib/workers/workerbase.cpp \
    ../../Course/CourseLib/core/gameobject.cpp \
    ../../Course/CourseLib/core/playerbase.cpp \
    ../../Game/mapitem.cpp \
    ../../Game/staticstorage.cpp \
    ../../Course/CourseLib/core/coordinate.cpp \
    ../../Game/objectmanager.cpp \
    ../../Course/CourseLib/core/worldgenerator.cpp \
    ../../Course/CourseLib/tiles/forest.cpp
