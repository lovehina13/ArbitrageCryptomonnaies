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

# HEADERS +=
# SOURCES +=

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra
