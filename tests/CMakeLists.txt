# CMakeLists.txt for building the Unit-tests.
# This is invoked by the top most CMakeLists.txt
#
# This directory contains several module-specific
# directories like 'version' for version related
# tests, etc.

# test modules
set(TEST_MODULES
    utils)

# iterate over all module directories
foreach (_module ${TEST_MODULES})

    # each source file inside ${_module} directory should
    # produce one unittest executable linked against GTest
    set(TEST_SRCS "")
    aux_source_directory(${_module} TEST_SRCS)
    foreach (_src ${TEST_SRCS})

        # name of executables should be same as source (w/o ext.)
        get_filename_component(_test ${_src} NAME_WE)
        add_executable(${_test} ${_src})

        # link against Tensor++; headers will be added automatically
        # as the headers are configured as INTERFACE dependencies
        target_link_libraries(${_test} PRIVATE ${NAME_OF_PROJECT})

        # link against GTest and expose GTest headers
        target_include_directories(${_test} PRIVATE ${GTEST_INCLUDE_DIRS})
        target_link_libraries(${_test} PRIVATE ${GTEST_BOTH_LIBRARIES} pthread)

        # this will help 'ctest' identify the executables as tests;
        # The test name convention is <module_name>_<test_source_name_WE>
        add_test(NAME ${_module}_${_test}
            COMMAND ${_test} WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
    endforeach ()
endforeach ()
