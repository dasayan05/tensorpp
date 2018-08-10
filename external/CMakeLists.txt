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

find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)
if (BLAS_FOUND AND LAPACK_FOUND)
    message(STATUS "Blas vendor found/specified: ${BLA_VENDOR}")
endif ()

list(GET LAPACK_LIBRARIES 0 LAPACK_LIBRARY)
get_filename_component(LAPACK_LIBRARY_DIR ${LAPACK_LIBRARY} DIRECTORY)

if (BLA_VENDOR STREQUAL "Intel10_64lp")
    set(BLAS_LIBNAME "mkl_rt")
    set(LAPACK_LIBNAME "mkl_rt")
else ()
    set(BLAS_LIBNAME "blas")
    set(LAPACK_LIBNAME "lapack")
endif ()

ExternalProject_Add(dl_lapackpp # a wrapper on lapack
    URL "https://sourceforge.net/projects/lapackpp/files/lapackpp-2.5.4.tar.gz"
    LOG_DOWNLOAD ON

    BUILD_IN_SOURCE 1
    CONFIGURE_COMMAND ./configure --prefix=<INSTALL_DIR> --enable-atlas=no --with-blas=${BLAS_LIBNAME} --with-lapack=${LAPACK_LIBNAME} --with-lapack-libs=${LAPACK_LIBRARY_DIR}
    BUILD_COMMAND make
    INSTALL_COMMAND make install
)

ExternalProject_Get_Property(dl_lapackpp install_dir)
add_library(lapackpp SHARED IMPORTED GLOBAL)
set_property(TARGET lapackpp PROPERTY IMPORTED_LOCATION ${install_dir}/lib/liblapackpp.so)

add_dependencies(lapackpp dl_lapackpp)
set(lapackpp_FOUND 1 PARENT_SCOPE)
set(lapackpp_INCLUDE_DIR ${install_dir}/include/lapackpp PARENT_SCOPE)
