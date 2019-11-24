TEMPLATE = app
TARGET = TheGame

QT += core gui widgets

CONFIG += c++14

SOURCES += \
    gamegraphicsview.cpp \
    itemlabel.cpp \
    main.cpp \
    gameeventhandler.cpp \
    objectmanager.cpp \
    boardinit.cpp \
    playerqlineedit.cpp \
    staticstorage.cpp \
    water.cpp \
    rock.cpp \
    sand.cpp \
    miner.cpp \
    farmer.cpp \
    mine.cpp \
    oilrig.cpp \
    mapitem.cpp \
    gamescene.cpp \
    player.cpp \
    mainwindow.cpp \
    dialog.cpp \
    lore.cpp

HEADERS += \
    gameeventhandler.h \
    gamegraphicsview.h \
    itemlabel.h \
    objectmanager.h \
    boardinit.h \
    playerqlineedit.h \
    staticstorage.h \
    water.h \
    rock.h \
    studentresourcemaps.h \
    sand.h \
    miner.h \
    farmer.h \
    mine.h \
    oilrig.h \
    mapitem.h \
    gamescene.h \
    player.h \
    mainwindow.h \
    dialog.h \
    lore.h

win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib

INCLUDEPATH += \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Course/CourseLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/libCourseLib.a

FORMS += \
    mainwindow.ui \
    dialog.ui \
    lore.ui

RESOURCES += \
    resources.qrc
