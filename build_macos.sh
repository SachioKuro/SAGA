#!/bin/bash

# Builds the project for MacOS.
if [ ! -d "build" ]; then
    mkdir build
fi

cmake -O . -B ./build -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=ON

# cp -R "./resource" "./build/bin/assets"

cd build && cmake --build . -v
echo compilation finished!