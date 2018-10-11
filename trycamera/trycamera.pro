#-------------------------------------------------
#
# Project created by QtCreator 2018-10-11T17:21:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = trycamera
TEMPLATE = app




SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH +=/usr/local/include\#附加头文件包含目录
              /usr/local/include/opencv\
              /usr/local/include/opencv2
LIBS +=-L/usr/local/lib\#链接库
        -lopencv_core\
        -lopencv_imgcodecs\
        -lopencv_highgui\
        -lopencv_imgproc


#Configs
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++14

#Libraries
unix: CONFIG += link_pkgconfig

#OpenCV
unix: PKGCONFIG += opencv
