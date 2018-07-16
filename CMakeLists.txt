# use modern CMake (i.e., cmake>=3.1)
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(tensorpp 
    VERSION 0.1  # version of Tensor++
    LANGUAGES CXX) # language in use (c++ only)

# set CXX standard; using cmake >= 3.1 makes it
# easy by CMAKE_CXX_STANDARD(..); C++11 *for now*
set(CMAKE_CXX_STANDARD 11)
set(PROJECT_VERSION ${${PROJECT_NAME}_VERSION})

# all options should go here
option(BUILD_BINARIES "Build the binaries ?" ON)
option(BUILD_64BIT "Build 64 bit library ?" ON)

# some convinient variables to
# use throughout cmake script
set(NAME_OF_PROJECT "${PROJECT_NAME}")
set(SOURCE_DIR "src")

# generate config.hpp file with configuration info
configure_file(${SOURCE_DIR}/tensor++/config.hpp.in config.hpp)

# Header-only library, so INTERFACE
add_library(${NAME_OF_PROJECT} INTERFACE)

# INTERFACE include directories;
# this is the reason every header file should have
# include statements like '#include <tensor++/xx.hpp>'
target_include_directories(${NAME_OF_PROJECT} INTERFACE ${SOURCE_DIR})
target_include_directories(${NAME_OF_PROJECT} INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

# build the binaries if requested
if (BUILD_BINARIES)
    add_subdirectory(bin)
endif ()