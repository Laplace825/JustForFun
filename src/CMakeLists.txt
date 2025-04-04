file(GLOB_RECURSE SOURCES "*.cc")

foreach(SOURCE ${SOURCES})
  get_filename_component(EXECUTABLE ${SOURCE} NAME_WE)
  log_info("Adding executable: ${EXECUTABLE}")
  add_executable(${EXECUTABLE} ${SOURCE})
endforeach()

