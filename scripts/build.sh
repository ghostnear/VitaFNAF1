#!/bin/bash

# Change this however you see fit
cmake -S .. -G "Ninja" -B ../build/ -DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DBUILD_TARGET=UNIX
cmake --build ../build