TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    DiagonalMatrix.cpp \
    Matrix.cpp \
    LowerTriangularMatrix.cpp

HEADERS += \
    DiagonalMatrix.h \
    Matrix.h \
    LowerTriangularMatrix.h
