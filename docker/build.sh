#!/bin/bash

mkdir -p /work/project/build
cd /work/project/build
i686-w64-mingw32.static-qmake-qt5 ../scad/scad.pro
make
