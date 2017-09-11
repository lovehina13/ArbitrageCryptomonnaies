#===============================================================================
# Name        : ArbitrageCryptomonnaies.pro
# Author      : Alexis Foerster (alexis.foerster@gmail.com)
# Version     : 1.0.0 (DD/MM/YYYY)
# Description : Qt project file of the ArbitrageCryptomonnaies project
#===============================================================================

TEMPLATE = app
TARGET = ArbitrageCryptomonnaies
DEPENDPATH += . include source
INCLUDEPATH += . include
OBJECTS_DIR = objects

HEADERS += include/Budget.h \
           include/Cours.h \
           include/Devise.h \
           include/Echange.h \
           include/Monnaie.h \
           include/Plateforme.h
SOURCES += source/ArbitrageCryptomonnaies.cpp \
           source/Budget.cpp \
           source/Cours.cpp \
           source/Devise.cpp \
           source/Echange.cpp \
           source/Monnaie.cpp \
           source/Plateforme.cpp

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra
