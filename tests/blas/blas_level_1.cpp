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
#include <array>

TEST(BlasLevelOne, _swap)
{
    std::array<double, 3> x1{+1.0, +2.0, +3.0};
    std::array<double, 3> x2{-1.0, -2.0, +5.0};

    const std::array<double, 3> x1c(x1);
    const std::array<double, 3> x2c(x2);

    cblas_dswap(3, x1.data(), 1, x2.data(), 1);

    for(size_t i = 0; i < 3; i++)
        ASSERT_EQ(x1.at(i), x2c.at(i));
    
    for(size_t i = 0; i < 3; i++)
        ASSERT_EQ(x2.at(i), x1c.at(i));
}