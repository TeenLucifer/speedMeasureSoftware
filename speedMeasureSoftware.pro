QT       += core gui serialport printsupport multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Algorithm.cpp \
    NewCombobox.cpp \
    main.cpp \
    mainwindow.cpp \
    mycombobox.cpp \
    qcustomplot.cpp

HEADERS += \
    Algorithm.h \
    NewCombobox.h \
    mainwindow.h \
    mycombobox.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += D:\software\opencv-4.2.0\build\install\include
LIBS += D:\software\opencv-4.2.0\build\lib\libopencv_*.a

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc
    RC_ICONS=TuRen.ico
