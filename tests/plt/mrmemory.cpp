#include <gtest/gtest.h>

#include "ptl/mrmemory"

TEST(TEST_MRMEMORY, CONSTRUCTOR)
{
    ASSERT_NO_THROW(ptl::mrmemory<int32_t> mrmemory(10));
}

TEST(TEST_MRMEMORY, METHOD_AT)
{
    ptl::mrmemory<int32_t> mrmemory_a(10);

    mrmemory_a.write(7, 2);

    ASSERT_EQ(mrmemory_a.at(7), 2);
}