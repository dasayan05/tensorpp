// the Tensor++ headers
#include <tensor++/tensor++.hpp>
using namespace tensorpp;

// GoogleTest headers
#include <gtest/gtest.h>

// standard headers
#include <string>

TEST(version, version_check_simple)
{
    ASSERT_EQ(version::get_version(), "0.1");
}
