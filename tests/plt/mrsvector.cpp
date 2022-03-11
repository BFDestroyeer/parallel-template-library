#include <gtest/gtest.h>

#include "ptl/mrsvector"

TEST(TEST_MRSVECTOR, CONSTRUCTOR)
{
    ASSERT_NO_THROW(ptl::mrsvector<int32_t> mrsvector(10));
}

TEST(TEST_MRSVECTOR, METHOD_AT)
{
    ptl::mrsvector<int32_t> mrsvector(10);

    mrsvector.write(0, 2);

    ASSERT_EQ(mrsvector.at(0), 2);
}

TEST(TEST_MRSVECTOR, METHOD_RESIZE)
{
    ptl::mrsvector<int32_t> mrsvector(7);

    mrsvector.resize(3);

    ASSERT_EQ(mrsvector.size(), 3);
}

TEST(TEST_MRSVECTOR, METHOD_PUSH_BACK)
{
    ptl::mrsvector<int32_t> mrsvector(7);

    mrsvector.push_back(2);

    ASSERT_EQ(mrsvector.at(7), 2);
}

TEST(TEST_MRSVECTOR, METHOD_POP_BACK)
{
    ptl::mrsvector<int32_t> mrsvector(7);

    mrsvector.pop_back();

    ASSERT_EQ(mrsvector.size(), 6);
}