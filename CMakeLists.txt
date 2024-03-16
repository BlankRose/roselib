cmake_minimum_required(VERSION 3.28)

project(roselib
    LANGUAGES CXX
    VERSION 0.1
    DESCRIPTION "Simple lightweight library, mostly intended for personal projects"
    HOMEPAGE_URL https://github.com/BlankRose/roselib)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

option(ROSELIB_BUILD_TEST "Should the test executable be built?" ON)

# ########################## #
#      PROJECT SOURCES       #
# ########################## #

set(LIB_HEADERS include/library.hpp)
set(LIB_SOURCES src/library.cpp)
set(TEST_SOURCES test/main.cpp)

# ########################## #
#        COMPILATION         #
# ########################## #

add_library(${PROJECT_NAME} STATIC ${LIB_SOURCES} ${LIB_HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE include)
if (${ROSELIB_BUILD_TEST})
    add_executable(${PROJECT_NAME}_test ${TEST_SOURCES})
    target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME})
    target_include_directories(${PROJECT_NAME}_test PRIVATE include)
endif ()

add_compile_options(-Wall -Wextra -Wpedantic -Wunreachable-code -Werror)
if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
    add_compile_options(-g3)
    if (NOT WIN32 AND ${ROSELIB_BUILD_TEST})
        target_link_options(${PROJECT_NAME}_test PRIVATE -fsanitize=address)
    endif ()
else () # MATCHES "Release"
    add_compile_options(-Ofast)
endif ()