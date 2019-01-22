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

#ifndef __TENSORPP__META__
#define __TENSORPP__META__

#include <tensorpp/utils/meta_structs.hpp>

/* standard library includes
 * must go at the very begining */
#include <string>

namespace tensorpp {

// the 'utils' namespace to contain version related routines and meta information
namespace utils {

    // get current Tensor++ version
    Version get_version();
    
    // get the platform name; i.e. OS
    OSEnum get_platform();

    // print configuration info
    void print_info(bool system = true, bool compiler = true, bool deps = false);
    
} // namespace 'utils'

} // namespace 'tensorpp'

#endif
