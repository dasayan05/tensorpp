// all internal/private dependencies
#include <tensorpp/tensorpp_internal.hpp>

#include <tensorpp/utils/meta_structs.hpp>

namespace tensorpp {

// the 'utils' namespace to contain utility
// routines and meta information
namespace utils {

    // get current Tensor++ version
    VersionStruct get_tensorpp_version() {
        return VersionStruct(TENSORPP_VERSION_MAJOR,
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
        // a local logger
        auto logger = spdlog::stdout_color_st(TENSORPP);
        logger->set_pattern("[%n:%L] %v");

        // start logging
        logger->info("Project: {}", TENSORPP);
        auto tensorpp_version = get_tensorpp_version();
        logger->info("Version: {}.{}.{}", 
            tensorpp_version._major,
            tensorpp_version._minor,
            tensorpp_version._patch);
        
        if (system)
        {
            const OSEnum os = get_platform();
            if (os == OSEnum::Windows)
                logger->info("System: Windows");
            else if (os == OSEnum::Linux)
                logger->info("System: Linux");
        }
        
        if (compiler)
            logger->info("{} ({}) compiler with C++{}", TENSORPP_CXX_COMPILER_ID,
                TENSORPP_CXX_COMPILER_VERSION, TENSORPP_CXX_STANDARD);

        if (deps)
        {
            #ifdef MKL_FOUND
                logger->info("CPU Backend: MKL");
            #else
                logger->info("CPU Backend: OpenBLAS");
            #endif
        }
    }
    
    
} // namespace 'version'

} // namespace 'tensorpp'
