file(GLOB_RECURSE SOURCES "*.cc")

include_directories(${PROJECT_ROOT_DIR}/include)

foreach(SOURCE ${SOURCES})
  get_filename_component(EXECUTABLE ${SOURCE} NAME_WE)
  log_info("Adding executable: ${EXECUTABLE}")
  add_executable(${EXECUTABLE} ${SOURCE})
endforeach()

