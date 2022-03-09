#include <gtest/gtest.h>

#include "ptl/mrvector"

TEST(TEST_MRVECTOR, CONSTRUCTOR_WITH_SIZE_PARAMETER)
{
    ASSERT_NO_THROW(ptl::mrvector<int32_t> vector(10));
}

TEST(TEST_MRVECTOR, METHOD_WRITE)
{
    ptl::mrvector<int32_t> vector_a(1);

    ASSERT_NO_THROW(vector_a.write(0, 2));
}

TEST(TEST_MRVECTOR, METHOD_AT)
{
    ptl::mrvector<int32_t> vector_a(1);

    vector_a.write(0, 2);

    ASSERT_EQ(vector_a.at(0), 2);
}
