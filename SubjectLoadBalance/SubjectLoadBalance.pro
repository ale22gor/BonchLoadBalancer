QT -= gui

TEMPLATE = lib
DEFINES += SUBJECTLOADBALANCE_LIBRARY

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    administrativeunit.cpp \
    course.cpp \
    group.cpp \
    lab.cpp \
    lecture.cpp \
    lesson.cpp \
    planingload.cpp \
    professor.cpp \
    realload.cpp \
    seminar.cpp \
    subgroup.cpp \
    subjectloadbalance.cpp \
    supergroup.cpp \
    teoreticalload.cpp \
    yearload.cpp

HEADERS += \
    Constants.h \
    SubjectLoadBalance_global.h \
    administrativeunit.h \
    course.h \
    group.h \
    lab.h \
    lecture.h \
    lesson.h \
    planingload.h \
    professor.h \
    realload.h \
    seminar.h \
    subgroup.h \
    subjectloadbalance.h \
    supergroup.h \
    teoreticalload.h \
    yearload.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
