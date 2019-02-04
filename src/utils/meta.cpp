#include <tensorpp/tensorpp_internal.hpp>

#include <tensorpp/utils/meta.hpp>
#include <tensorpp/utils/logger.hpp>

namespace tensorpp {

// the 'utils' namespace to contain utility
// routines and meta information
namespace utils {

    // get current Tensor++ version
    Version get_version() {
        return Version(TENSORPP_VERSION_MAJOR,
                       TENSORPP_VERSION_MINOR,
                       TENSORPP_VERSION_PATCH);
    }
    
    // get the platform/OS name
    OSEnum get_platform() {
        #ifdef UNIX
            return OSEnum::Linux;
        #elif WIN32
            return OSEnum::Windows;
        #endif
    }

    // print configuration info
    void print_info(bool system, bool compiler, bool deps) {
        
        auto tensorpp_version = get_version();
        TPP_INFO("Version: {}.{}.{}",
            tensorpp_version._major,
            tensorpp_version._minor,
            tensorpp_version._patch);
        
        if (system)
        {
            const OSEnum os = get_platform();
            if (os == OSEnum::Windows)
                TPP_INFO("System: Windows");
            else if (os == OSEnum::Linux)
                TPP_INFO("System: Linux");
        }
        
        if (compiler)
            TPP_INFO(
                "{} ({}) compiler with C++{}", TENSORPP_CXX_COMPILER_ID,
                                               TENSORPP_CXX_COMPILER_VERSION,
                                               TENSORPP_CXX_STANDARD);

        if (deps)
        {
            #ifdef MKL_FOUND
                TPP_INFO("CPU Backend: MKL");
            #else
                TPP_INFO("CPU Backend: OpenBLAS");
            #endif
        }

    }
    
    
} // namespace 'utils'

} // namespace 'tensorpp'
