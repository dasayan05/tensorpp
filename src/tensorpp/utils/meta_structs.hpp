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

#ifndef __TENSORPP__META_STRUCTS__
#define __TENSORPP__META_STRUCTS__

/* standard library includes
 * must go at the very begining */
#include <cstdint>

namespace tensorpp {
// the 'version' namespace to contain version
// related routines and meta information
namespace utils {
	
	/* A structure that holds version number
	 * an may (TODO) provide some version
	 * manipulation functionalities
	 */
	typedef
	struct _version_struct {
		std::uint8_t _major = 1;
		std::uint8_t _minor = 0;
		std::uint8_t _patch = 0;
		constexpr _version_struct(uint8_t _major, uint8_t _minor, uint8_t _patch) :
			_major(_major), _minor(_minor), _patch(_patch)
		{
			// ...
		}
	}
	VersionStruct;
	
	/*
	 * System architecture enum
	 */
	enum class SysArch {
		BIT_32,
		BIT_64
	};
	
} // namespace 'version'

} // namespace 'tensorpp'

#endif