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

// GoogleTest headers
#include <gtest/gtest.h>

// the Tensor++ headers
#include <tensorpp/tensorpp.hpp>
using namespace tensorpp;

// standard headers
#include <string>

TEST(meta, version_check)
{
	auto tensorpp_version = utils::get_tensorpp_version();
    ASSERT_EQ(tensorpp_version._major, TENSORPP_VERSION_MAJOR);
    ASSERT_EQ(tensorpp_version._minor, TENSORPP_VERSION_MINOR);
    ASSERT_EQ(tensorpp_version._patch, TENSORPP_VERSION_PATCH);
}

TEST(meta, system_check)
{
    auto tensorpp_system = utils::get_system_name();
    ASSERT_EQ(tensorpp_system, TENSORPP_SYSTEM);
}
