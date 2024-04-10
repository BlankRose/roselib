# ############################################################################ #
#          .-.                                                                 #
#    __   /   \   __                                                           #
#   (  `'.\   /.'`  )  CMakeLists.txt                                          #
#    '-._.(;;;)._.-'                                                           #
#    .-'  ,`"`,  '-.                                                           #
#   (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)                #
#       //\   /        Last Updated: March 23, 2024 [08:43 pm]                 #
#      ||  '-'                                                                 #
# ############################################################################ #

cmake_minimum_required(VERSION 3.20)

project(roselib
    LANGUAGES CXX
    DESCRIPTION "Simple lightweight library, mostly intended for personal projects"
    HOMEPAGE_URL https://github.com/BlankRose/roselib)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

option(ROSELIB_BUILD_TEST "Should the test executable be built?" ON)

# ########################## #
#      PROJECT SOURCES       #
# ########################## #

set(LIB_HEADERS
        include/roselib/AnsiSequence.hpp
        include/roselib/impl/predicates.tpp
        include/roselib/Predicates/begin_with.hpp
        include/roselib/Predicates/end_with.hpp
        include/roselib/Predicates.hpp
        include/roselib/impl/tester.tpp
        include/roselib/UnitTester/utils.hpp
        include/roselib/UnitTester/UnitTesterBase.hpp
        include/roselib/UnitTester/UnitTesterConditional.hpp
        include/roselib/UnitTester/UnitTesterFunction.hpp
        include/roselib/UnitTester/UnitTesterObject.hpp
        include/roselib/UnitTester.hpp
        include/roselib/Logger.hpp
        include/roselib.hpp)
set(LIB_SOURCES
        src/UnitTesterBase.cpp
        src/UnitTesterConditional.cpp
        src/Logger.cpp)
set(TEST_SOURCES
        test/main.cpp
        test/callback.cpp
        test/unit_tester.cpp
        test/begin_with.cpp
        test/end_with.cpp
        test/logger.cpp)

# ########################## #
#        COMPILATION         #
# ########################## #

add_library(${PROJECT_NAME} STATIC ${LIB_SOURCES} ${LIB_HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC include)
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