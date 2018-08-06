# This is a CMake file dedicated to
# resolve and include all the required
# external dependencies of Tensor++

# need 'ExternalProject_Add'
include(ExternalProject)

ExternalProject_Add(spdlog # a fast C++ logging library
    GIT_REPOSITORY "https://github.com/gabime/spdlog"
    GIT_TAG "v1.0.0"
    PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
    CMAKE_ARGS "-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER} -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}"
    LOG_DOWNLOAD ON

    CONFIGURE_COMMAND "" # no need for configure,
    BUILD_COMMAND ""     # build, install and
    INSTALL_COMMAND ""   # update steps because
    UPDATE_COMMAND ""    # it's header only
)

ExternalProject_Get_Property(spdlog source_dir)
set(spdlog_FOUND 1 PARENT_SCOPE)
set(spdlog_INCLUDE_DIR "${source_dir}/include" PARENT_SCOPE)
