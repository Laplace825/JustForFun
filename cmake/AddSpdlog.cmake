include("${CMAKE_CURRENT_SOURCE_DIR}/Logging.cmake")

find_package(Git QUIET)


if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    if(EXISTS "${PROJECT_SOURCE_DIR}/extern/spdlog/CMakeLists.txt")
        log_info("The submodules were downloaded! GIT_SUBMODULE was turned off.")
    endif()
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        log_info("Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            log_fatal("git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()
