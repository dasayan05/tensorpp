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

// the Tensor++ headers
#include <tensorpp/tensorpp.hpp>
using namespace tensorpp;

// GoogleTest headers
#include <gtest/gtest.h>

TEST(BLAS1, DotProduct)
{
    double vec1[] = {+1.0, +2.0, +1.0};
    double vec2[] = {-1.0, +4.0, -2.0};

    LaVectorDouble l1(vec1, 3);
    LaVectorDouble l2(vec2, 3);

    double d = Blas_Dot_Prod(l1, l2);
    ASSERT_EQ(d, 5.0);
}
