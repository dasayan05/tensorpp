# use modern CMake (i.e., cmake>=3.1)
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(tensorpp 
    VERSION 0.1  # version of Tensor++
    LANGUAGES CXX) # language in use (c++ only)

# include helper scripts to activate latest C++ standard
include(cmake/CXXSTD.cmake)
message(STATUS "C++${LATEST_CXX_STD} detected and activated.")

set(PROJECT_VERSION ${${PROJECT_NAME}_VERSION})

# all options should go here
option(BUILD_BINARIES "Build the binaries ?" ON)
option(BUILD_TESTS "Build tests ?" ON)
option(BUILD_64BIT "Build 64 bit library ?" ON)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(DEBUG 1)
endif ()

# some convinient variables to
# use throughout cmake script
set(NAME_OF_PROJECT "${PROJECT_NAME}")
set(SOURCE_DIR "src")

# generate config.hpp file with configuration info
configure_file(${SOURCE_DIR}/tensorpp/config.hpp.in config.hpp)

# Header-only library, so INTERFACE
add_library(${NAME_OF_PROJECT} INTERFACE)
# add the headers as sources so that
# IDE's can show them properly
# TODO: GLOBing NOT recommended, find other way
file(GLOB_RECURSE HEADERS_LIST "${SOURCE_DIR}/*.hpp")
target_sources(${NAME_OF_PROJECT} INTERFACE ${HEADERS_LIST})

# INTERFACE include directories;
# this is the reason every header file should have
# include statements like '#include <tensorpp/**/*.hpp>'
# OR, simply '#include <tensorpp/tensorpp.hpp>'
target_include_directories(${NAME_OF_PROJECT} INTERFACE ${SOURCE_DIR})
target_include_directories(${NAME_OF_PROJECT} INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

# get external dependencies
add_subdirectory(external)
# apply external dependencies
if (spdlog_FOUND)
    target_include_directories(${NAME_OF_PROJECT} INTERFACE ${spdlog_INCLUDE_DIR})
endif ()
if (cxxopts_FOUND)
    target_include_directories(${NAME_OF_PROJECT} INTERFACE ${cxxopts_INCLUDE_DIR})
endif ()

# build the binaries if requested
if (BUILD_BINARIES)
    add_subdirectory(bin)
endif ()

# unit testing with GoogleTest
find_package(GTest)

if (BUILD_TESTS AND GTEST_FOUND)
    # make tests runnable via ctest
    enable_testing()
    # contains unit tests and build procedure
    add_subdirectory(tests)
endif ()
