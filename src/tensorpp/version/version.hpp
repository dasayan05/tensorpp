/*
 *  Copyright (C) 2018
 *  @author Ayan Das
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.

 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef __TENSORPP__VERSION__
#define __TENSORPP__VERSION__

/* standard library includes
 * must go at the very begining */
#include <iostream>
#include <string>


#ifdef CXXSTD_17
namespace tensorpp::version {
#else
namespace tensorpp {
// the 'version' namespace to contain version
// related routines and meta information
namespace version {
#endif

    // print configuration info
    void print_info() {
        // a local logger
        auto logger = spdlog::stdout_color_st("tensorpp");
        logger->set_pattern("[%n:%L] %v");

        // start logging
        logger->info("Project: {}", NAME_OF_PROJECT);
        logger->info("Version: {}", PROJECT_VERSION);
        logger->info("System: {}",
        #ifdef UNIX
            "Linux"
        #endif
        #ifdef WIN32
            "Windows"
        #endif
        );

        #ifdef IS_64BIT
            logger->info("Built with 64 bit");
        #endif

        logger->info("{} ({}) compiler with C++{}", CMAKE_CXX_COMPILER_ID,
            CMAKE_CXX_COMPILER_VERSION, LATEST_CXX_STD);
    }

    std::string get_version() {
        return std::string(PROJECT_VERSION);
    }
#ifdef CXXSTD_17
} // namespace 'tensorpp::version'
#else
} // namespace 'version'

} // namespace 'tensorpp'
#endif

#endif
