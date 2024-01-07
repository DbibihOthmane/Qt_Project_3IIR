QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    afficher.cpp \
    ajouter.cpp \
    application.cpp \
    main.cpp \
    mainwindow.cpp \
    modif.cpp \
    supprimer.cpp

HEADERS += \
    afficher.h \
    ajouter.h \
    application.h \
    mainwindow.h \
    modif.h \
    supprimer.h

FORMS += \
    afficher.ui \
    ajouter.ui \
    application.ui \
    mainwindow.ui \
    modif.ui \
    supprimer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    projet-QT.pro.user
