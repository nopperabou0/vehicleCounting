#!/bin/bash

CXX="clang++"
CXXFLAGS="-v"
SRC="main.cpp"
OUTPUT="vehicleCounter"

INCLUDES="-I. -I./include"

LIBDIR="./lib64"
LIB_PATH="-L${LIBDIR}"
RPATH="-Wl,-rpath,${LIBDIR}"

LIBS="-lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc -lopencv_dnn"

build_app() {
    echo "Building ${OUTPUT} with source ${SRC}"
    ${CXX} ${CXXFLAGS} ${SRC} -o ${OUTPUT} ${RPATH} ${INCLUDES} ${LIB_PATH} ${LIBS}
}

build_app

if [ $? -eq 0 ]; then
    echo "Build succeeded: ${OUTPUT} created."
else
    echo "Build failed." >&2
    exit 1
fi
