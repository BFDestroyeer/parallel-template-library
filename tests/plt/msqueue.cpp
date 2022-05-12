#include <gtest/gtest.h>

#include "ptl/msqueue"

TEST(TEST_MSQUEUE, CONSTRUCTOR)
{
    ASSERT_NO_THROW(ptl::msqueue<int32_t> queue);
}

TEST(TEST_MSQUEUE, METHOD_PUSH)
{
    ptl::msqueue<int32_t> queue;
    queue.push(10);
}

TEST(TEST_MSQUEUE, METHOD_POP)
{
    ptl::msqueue<int32_t> queue;
    queue.push(10);
    queue.pop();
}