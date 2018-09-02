// required header in all source files
#include <tensorpp/tensorpp.hpp>

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
    
    // get the system name; i.e. OS
    std::string get_system_name() {
        return std::string(TENSORPP_SYSTEM);
    }
    
    // get platform architecture
    SysArch get_system_arch() {
        #ifdef TENSORPP_64BIT
            return SysArch::BIT_64;
        #else
            return SysArch::BIT_32;
        #endif
    }

    // print configuration info
    void print_info(bool system, bool compiler) {
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
        
        if (system) {
            logger->info("System: {}", get_system_name());
            
            if (get_system_arch() == SysArch::BIT_64)
                logger->info("Built with 64 bit");
            else
                logger->info("Built with 32 bit");
        }
        
        if (compiler)
            logger->info("{} ({}) compiler with C++{}", TENSORPP_CXX_COMPILER_ID,
                TENSORPP_CXX_COMPILER_VERSION, TENSORPP_CXX_STANDARD);
    }
    
    
} // namespace 'version'

} // namespace 'tensorpp'
