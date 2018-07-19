# contains helper scripts to detect and
# activate the latest C++ standard available
# in the compiler detected/provided.

function (set_latest_cxx_std_gcc)
    if (${CMAKE_CXX_COMPILER_VERSION} VERSION_GREATER "7.0")
        # .. set C++ 17
        set(CMAKE_CXX_STANDARD 17 PARENT_SCOPE)
    elseif (${CMAKE_CXX_COMPILER_VERSION} VERSION_GREATER "6.1")
        # .. set C++ 14
        set(CMAKE_CXX_STANDARD 14 PARENT_SCOPE)
    elseif (${CMAKE_CXX_COMPILER_VERSION} VERSION_GREATER "4.8.1")
        # .. set C++ 11
        set(CMAKE_CXX_STANDARD 11 PARENT_SCOPE)
    else ()
        # .. Oops, atleast C++11 needed
        message(FATAL_ERROR "Having a C++11 supported compiler is a requirement")
    endif ()
endfunction (set_latest_cxx_std_gcc)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    set_latest_cxx_std_gcc()
else ()
    message(FATAL_ERROR "Compiler not supported")
endif ()