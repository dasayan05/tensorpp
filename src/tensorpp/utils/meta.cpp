#include <tensorpp/tensorpp_internal.hpp>

#include <tensorpp/utils/meta_structs.hpp>
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
        logger(LogLevel::Info, 
            "Version: {}.{}.{}", tensorpp_version._major,
                                 tensorpp_version._minor,
                                 tensorpp_version._patch);
        
        if (system)
        {
            const OSEnum os = get_platform();
            if (os == OSEnum::Windows)
                logger(LogLevel::Info, "System: Windows");
            else if (os == OSEnum::Linux)
                logger(LogLevel::Info, "System: Linux");
        }
        
        if (compiler)
            logger(LogLevel::Info,
                "{} ({}) compiler with C++{}", TENSORPP_CXX_COMPILER_ID,
                                               TENSORPP_CXX_COMPILER_VERSION,
                                               TENSORPP_CXX_STANDARD);

        if (deps)
        {
            #ifdef MKL_FOUND
                logger(LogLevel::Info, "CPU Backend: MKL");
            #else
                logger(LogLevel::Info, "CPU Backend: OpenBLAS");
            #endif
        }

    }
    
    
} // namespace 'utils'

} // namespace 'tensorpp'
