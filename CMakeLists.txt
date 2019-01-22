# use modern CMake (i.e., cmake>=3.1)
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(tensorpp 
    VERSION 0.1.0  # version of Tensor++
    LANGUAGES CXX) # language in use (c++ only)

# make the cmake scripts in "./cmake/" visible to CMake
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# include helper scripts to activate latest C++ standard
include(cmake/CXXSTD.cmake)

# all options should go here
option(BUILD_BINARIES "Build the binaries ?" ON)
option(BUILD_TESTS "Build tests ?" ON)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(DEBUG 1)
endif ()

# some convinient variables to use throughout cmake script
set(SOURCE_DIR "src")

# MKL/OpenBLAS dependencies checking
find_package(MKL)
if (MKL_FOUND)
    message(STATUS "Using MKL (and not OpenBLAS)")
else ()
    find_package(OpenBLAS REQUIRED)
    if (OpenBLAS_FOUND)
        message(STATUS "Using OpenBLAS, because MKL not found")
    endif ()
endif ()

# generate config.hpp file with configuration info
configure_file(${SOURCE_DIR}/tensorpp/config.hpp.in config.hpp)

# produce STATIC library
file(GLOB_RECURSE SOURCE_LIST "${SOURCE_DIR}/*.cpp")
add_library(${PROJECT_NAME} STATIC ${SOURCE_LIST})

# This is the reason every header/src file should have
# include statements like '#include <tensorpp/**/*.hpp>'
# OR, simply '#include <tensorpp/tensorpp.hpp>'
target_include_directories(${PROJECT_NAME} PUBLIC ${SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC  # This is for 'config.hpp'
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

# External dependencies:

# The 'fmt' library for logger formatting
add_subdirectory(external/fmt)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

# The 'MKL'/'OpenBLAS' libraries for core computational primitives
if (MKL_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${MKL_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${MKL_LIBRARIES})
else ()
    target_include_directories(${PROJECT_NAME} PRIVATE ${OpenBLAS_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenBLAS_LIB})
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
