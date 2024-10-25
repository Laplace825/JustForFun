cmake_minimum_required(VERSION 3.30)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

project(justforfun LANGUAGES CXX)
set(PROJECT_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Logging.cmake")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_ROOT_DIR}/bin")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src")
