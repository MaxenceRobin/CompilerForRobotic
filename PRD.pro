#-------------------------------------------------
#
# Project created by QtCreator 2018-12-24T12:57:01
#
#-------------------------------------------------

QT       += core gui webenginewidgets webchannel

greaterThan(QT_MAJOR_VERSION, 4): QT += \
    widgets \
    webenginewidgets \
    serialport

TARGET = PRD
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# ANTLR RUNTIME DEPENCY

INCLUDEPATH += \
    ..\..\..\..\ANTLR\RUNTIME\antlr4-cpp-runtime-4.7.1-vs2015\antlr4-runtime

DEPENDPATH += \
    ..\..\..\..\ANTLR\RUNTIME\antlr4-cpp-runtime-4.7.1-vs2015\antlr4-runtime

#######################

CONFIG += c++11

SOURCES += \
    main.cpp \
    views/mainwindow.cpp \
    ANTLR/antlr4-runtime/PivotBaseVisitor.cpp \
    ANTLR/antlr4-runtime/PivotLexer.cpp \
    ANTLR/antlr4-runtime/PivotParser.cpp \
    ANTLR/antlr4-runtime/PivotVisitor.cpp \
    compilers/micropython/micropythoncompiler.cpp \
    models/programfile.cpp \
    models/projecttypelist.cpp \
    editors/blockly/blocklyneutralroboteditor.cpp \
    executors/micropython/micropythongeneratorexecutor.cpp \
    editors/abstracteditor.cpp \
    executors/abstractexecutor.cpp \
    models/projecttype.cpp \
    views/createprogramview.cpp \
    models/settings.cpp \
    editors/blockly/baseblocklyeditor.cpp \
    senders/wipy/wipysender.cpp \
    senders/abstractsender.cpp

HEADERS += \
    views/mainwindow.h \
    ANTLR/antlr4-runtime/PivotBaseVisitor.h \
    ANTLR/antlr4-runtime/PivotLexer.h \
    ANTLR/antlr4-runtime/PivotParser.h \
    ANTLR/antlr4-runtime/PivotVisitor.h \
    compilers/micropython/micropythoncompiler.h \
    models/programfile.h \
    models/projecttype.h \
    models/projecttypelist.h \
    editors/blockly/blocklyneutralroboteditor.h \
    executors/micropython/micropythongeneratorexecutor.h \
    editors/abstracteditor.h \
    executors/abstractexecutor.h \
    views/createprogramview.h \
    models/settings.h \
    editors/blockly/baseblocklyeditor.h \
    senders/wipy/wipysender.h \
    senders/abstractsender.h

FORMS += \
    views/mainwindow.ui \
    views/createprogramview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -L$$PWD/'../../../../ANTLR/RUNTIME/antlr4-cpp-runtime-4.7.1-vs2015/lib/vs-2015/x64/Release DLL/' -lantlr4-runtime

INCLUDEPATH += $$PWD/'../../../../ANTLR/RUNTIME/antlr4-cpp-runtime-4.7.1-vs2015/lib/vs-2015/x64/Release DLL'
DEPENDPATH += $$PWD/'../../../../ANTLR/RUNTIME/antlr4-cpp-runtime-4.7.1-vs2015/lib/vs-2015/x64/Release DLL'

RESOURCES += \
    resources.qrc
