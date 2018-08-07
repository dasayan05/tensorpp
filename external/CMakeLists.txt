# This is a CMake file dedicated to
# resolve and include all the required
# external dependencies of Tensor++

# need 'ExternalProject_Add'
include(ExternalProject)

ExternalProject_Add(spdlog # a fast C++ logging library
    URL "https://github.com/gabime/spdlog/archive/v1.0.0.tar.gz"
    LOG_DOWNLOAD ON

    CONFIGURE_COMMAND "" # no need for configure,
    BUILD_COMMAND ""     # build, install and
    INSTALL_COMMAND ""   # update steps because
    UPDATE_COMMAND ""    # it's header only
)

ExternalProject_Get_Property(spdlog source_dir)
set(spdlog_FOUND 1 PARENT_SCOPE)
set(spdlog_INCLUDE_DIR "${source_dir}/include" PARENT_SCOPE)

ExternalProject_Add(cxxopts # a fast cmdline parser
	URL "https://github.com/jarro2783/cxxopts/archive/v2.1.1.tar.gz"
	LOG_DOWNLOAD ON
	
	CONFIGURE_COMMAND "" # no need for configure,
    BUILD_COMMAND ""     # build, install and
    INSTALL_COMMAND ""   # update steps because
    UPDATE_COMMAND ""    # it's header only
)

ExternalProject_Get_Property(cxxopts source_dir)
set(cxxopts_FOUND 1 PARENT_SCOPE)
set(cxxopts_INCLUDE_DIR "${source_dir}/include" PARENT_SCOPE)