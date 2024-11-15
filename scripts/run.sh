#!/bin/bash

PROJECT_ROOT_DIR=$(pwd)

echo_warning() {
  echo -e "\033[1;33m[warn]\033[0m $1"
}

echo_info() {
  echo -e "\033[1;36m[info]\033[0m $1"
}

# ===================================================== #
# Run the project                                       #
#                                                       #
# if the build directory does not exist, call build.sh  #
# ===================================================== #

if [ ! -d "build" ]; then
  echo_warning "Build directory does not exist. Running build.sh"
  bash scripts/build.sh
fi

# if the build directory still does not exist, exit
if [ ! -d "build" ]; then
  echo_warning "Build directory STILL does not exist. Exiting."
  exit 1
fi

# if the build directory exists, run the project
pushd "${PROJECT_ROOT_DIR}/bin" >/dev/null || exit

for file in $(/bin/ls); do
  if [ -x "$file" ]; then
    echo_info "Running $file"
    ./"${file}"
    if [ ! $? ]; then
      echo_warning "Error running $file, maybe C++20 not supported"
    fi
  fi
done

popd >/dev/null || exit
