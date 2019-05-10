TEMPLATE = subdirs

CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage -O0

SUBDIRS = Libraries tests

CONFIG += ordered

# C++11
QMAKE_CXXFLAGS += -std=c++11
