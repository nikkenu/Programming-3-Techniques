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
    ../../Game/gameeventhandler.h \
    ../../Game/player.h \
    ../../Course/CourseLib/core/playerbase.h \
    ../../Course/CourseLib/core/resourcemaps.h \
    ../../Course/CourseLib/interfaces/igameeventhandler.h \
    ../../Game/objectmanager.h \
    ../../Game/gamescene.h \
    ../../Game/boardinit.h \
    ../../Game/gamegraphicsview.h \
    ../../Course/CourseLib/core/coordinate.h \
    ../../Course/CourseLib/core/gameobject.h \
    ../../Course/CourseLib/core/placeablegameobject.h \
    ../../Game/mapitem.h \
    ../../Game/staticstorage.h \
    ../../Course/CourseLib/core/worldgenerator.h \
    ../../Game/water.h \
    ../../Game/sand.h \
    ../../Game/rock.h \
    ../../Game/oilrig.h \
    ../../Game/miner.h \
    ../../Game/mine.h \
    ../../Game/farmer.h \
    ../../Course/CourseLib/buildings/outpost.h \
    ../../Course/CourseLib/buildings/headquarters.h \
    ../../Course/CourseLib/buildings/farm.h \
    ../../Course/CourseLib/buildings/buildingbase.h \
    ../../Course/CourseLib/workers/workerbase.h \
    ../../Course/CourseLib/workers/basicworker.h \
    ../../Course/CourseLib/tiles/grassland.h \
    ../../Course/CourseLib/tiles/forest.h \
    ../../Course/CourseLib/tiles/tilebase.h \
    ../../Course/CourseLib/core/basicresources.h


SOURCES +=  tst_gameeventhandlertest.cpp \
    ../../Game/gameeventhandler.cpp \
    ../../Game/player.cpp \
    ../../Course/CourseLib/core/playerbase.cpp \
    ../../Game/objectmanager.cpp \
    ../../Game/gamescene.cpp \
    ../../Game/boardinit.cpp \
    ../../Game/gamegraphicsview.cpp \
    ../../Course/CourseLib/core/coordinate.cpp \
    ../../Course/CourseLib/core/gameobject.cpp \
    ../../Course/CourseLib/core/placeablegameobject.cpp \
    ../../Game/mapitem.cpp \
    ../../Game/staticstorage.cpp \
    ../../Course/CourseLib/core/worldgenerator.cpp \
    ../../Game/water.cpp \
    ../../Game/sand.cpp \
    ../../Game/rock.cpp \
    ../../Game/oilrig.cpp \
    ../../Game/miner.cpp \
    ../../Game/mine.cpp \
    ../../Game/farmer.cpp \
    ../../Course/CourseLib/buildings/outpost.cpp \
    ../../Course/CourseLib/buildings/headquarters.cpp \
    ../../Course/CourseLib/buildings/farm.cpp \
    ../../Course/CourseLib/buildings/buildingbase.cpp \
    ../../Course/CourseLib/workers/workerbase.cpp \
    ../../Course/CourseLib/workers/basicworker.cpp \
    ../../Course/CourseLib/tiles/grassland.cpp \
    ../../Course/CourseLib/tiles/forest.cpp \
    ../../Course/CourseLib/tiles/tilebase.cpp \
    ../../Course/CourseLib/core/basicresources.cpp
