QT       += core gui svg network serialport quick qml network positioning location quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Connections.cpp \
    Delegate.cpp \
    TcpMcuClient.cpp \
    Uav_settings.cpp \
    UdpMcuClient.cpp \
    chart_data.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    Connections.h \
    Delegate.h \
    GPS/vehicle_gps_position.h \
    MainWindow.h \
    TcpMcuClient.h \
    Uav_settings.h \
    UdpMcuClient.h \
    chart_data.h

FORMS += \
    Connections.ui \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images_and_icons.qrc \
    qml.qrc

DISTFILES += \
    images/uav.png

include(qfi/qfi.pri)
