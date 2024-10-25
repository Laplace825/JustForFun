#!/bin/bash

# ===================================================== #
# Build the project
#
# if the build directory does not exist, create it
# ===================================================== #

if [ ! -d "build" ]; then
  mkdir -p build
fi

cmake -S . -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
  -DCMAKE_CXX_FLAGS="-Wall -Wextra -Werror -Wno-unused-variable"
  # do not warn about unused variables in compile flag


ninja -C build -j 8 -v
