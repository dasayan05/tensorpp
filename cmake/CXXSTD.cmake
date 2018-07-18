# contains helper scripts to detect and
# activate the latest C++ standard available
# in the compiler detected/provided.

function (get_latest_cxx_std_gcc ver_major ver_minor ver_patch standard)
    if ((${ver_major} EQUAL 7) OR (${ver_major} GREATER 7))
        # .. set C++ 17
    elseif ((${ver_major} EQUAL 6) AND
            ((${ver_minor} EQUAL 1) OR (${ver_minor} GREATER 1)))
        # .. set C++ 14
    elseif ((${ver_major} EQUAL 4) AND (${ver_major} EQUAL 8) AND
            ((${ver_patch} EQUAL 1) OR (${ver_patch} GREATER 1)))
        # .. set C++ 11
    else ()
        # .. Oops, atleast C++11 needed
    endif ()
endfunction (get_latest_cxx_std_gcc)