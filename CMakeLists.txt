cmake_minimum_required(VERSION 3.30)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

project(justforfun LANGUAGES CXX)
set(PROJECT_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Logging.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/CompilerVersionCheck.cmake")
# include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/AddSpdlog.cmake")
configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/template/config.h.in"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/config.h"
  @ONLY
)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_ROOT_DIR}/bin")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src")
