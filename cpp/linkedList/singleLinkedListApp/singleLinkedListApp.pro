QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

TEMPLATE += app

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    SingleList.cpp \
    SingleNode.cpp

HEADERS += \
    SingleList.h \
    SingleNode.h

#MYDLLDIR = $$(ALGODIR)\dllLists

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
#!isEmpty(target.path): INSTALLS += MYDLLDIR



# As our header files are in the same directory, we can make Qt Creator find it
# by specifying it as INCLUDEPATH.
#INCLUDEPATH += $$MYDLLDIR

# Dependency to library domain (libdomain.so for Unices or domain.dll on Win32)
# Repeat this for more libraries if needed.
#win32:LIBS += $$quote($$MYDLLDIR\lists.dll)
# unix:LIBS += $$quote(-L$$MYDLLDIR) -llists

#message(The project will read in $$quote($$MYDLLDIR\lists.dll))




#DDIR = \"$$MYDLLDIR/\"
#SDIR = \"$$IN_PWD/\"
# Replace slashes in paths with backslashes for Windows
#win32:SDIR ~= s,/,\\,g
# For-loop to copy all header files to DDIR.
#QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$MYDLLDIR\lists.dll) $$quote($$SDIR) $$escape_expand(\\n\\t)


