# contains helper scripts to detect and
# activate the latest C++ standard available
# in the compiler detected/provided.

function (get_latest_cxx_std_gcc version_string standard)
    if (${version_string} VERSION_GREATER 7.0)
        # .. set C++ 17
    elseif (${version_string} VERSION_GREATER 6.1)
        # .. set C++ 14
    elseif (${version_string} VERSION_GREATER 4.8.1)
        # .. set C++ 11
    else ()
        # .. Oops, atleast C++11 needed
    endif ()
endfunction (get_latest_cxx_std_gcc)