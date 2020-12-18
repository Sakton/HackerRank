TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        queen.cpp

HEADERS += \
	Point.h \
	queen.h

DISTFILES += \
	table.ods
