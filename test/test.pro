TEMPLATE = app
CONFIG -= app_bundle
CONFIG += console
QT += sql

isEmpty(BOOST_INCLUDE_DIR): BOOST_INCLUDE_DIR=$$(BOOST_INCLUDE_DIR)
!isEmpty(BOOST_INCLUDE_DIR): INCLUDEPATH *= $${BOOST_INCLUDE_DIR}

isEmpty(BOOST_INCLUDE_DIR): {
    message("BOOST_INCLUDE_DIR is not set, assuming Boost can be found automatically in your system")
}

SOURCES += \
    main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SubjectLoadBalance/release/ -lSubjectLoadBalance
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SubjectLoadBalance/debug/ -lSubjectLoadBalance
else:unix: LIBS += -L$$OUT_PWD/../SubjectLoadBalance/ -lSubjectLoadBalance

INCLUDEPATH += $$PWD/../SubjectLoadBalance
DEPENDPATH += $$PWD/../SubjectLoadBalance

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Repositories/release/ -lRepositories
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Repositories/debug/ -lRepositories
else:unix: LIBS += -L$$OUT_PWD/../Repositories/ -lRepositories

INCLUDEPATH += $$PWD/../Repositories
DEPENDPATH += $$PWD/../Repositories
