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

        std::cout << CMAKE_CXX_COMPILER_ID <<
            " (" << CMAKE_CXX_COMPILER_VERSION << ") compiler with C++" << CMAKE_CXX_STANDARD << '\n';
        std::cout << std::flush;
    }

    std::string get_version() {
        return std::string(PROJECT_VERSION);
    }

} // namespace 'version'

} // namespace 'tensorpp'

#endif
