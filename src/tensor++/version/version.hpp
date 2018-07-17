#ifndef __TENSORPP__VERSION__
#define __TENSORPP__VERSION__

/* standard library includes
 * must go at the very begining */
#include <iostream>
#include <string>

namespace tensorpp {
// the 'version' namespace to contain version
// related routines and meta information
namespace version {

    // print configuration info
    void print_info() {
        std::cout << "Project: " << NAME_OF_PROJECT << '\n';
        std::cout << "Version: " << PROJECT_VERSION << '\n';
        std::cout << "System: " <<
        #ifdef UNIX
            "Linux"
        #endif
        #ifdef WIN32
            "Windows"
        #endif
            << '\n';

        #ifdef IS_64BIT
            std::cout << "Built with 64 bit" << '\n';
        #endif

        std::cout << CMAKE_CXX_COMPILER_ID << " compiler with C++ " << CMAKE_CXX_STANDARD << '\n';
        std::cout << std::flush;
    }

    std::string get_version() {
        return std::string(PROJECT_VERSION);
    }

} // namespace 'version'

} // namespace 'tensorpp'

#endif
