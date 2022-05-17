#include <gtest/gtest.h>

#include "ptl/bqueue"

TEST(TEST_BQUEUE, CONSTRUCTOR)
{
    ASSERT_NO_THROW(ptl::bqueue<int32_t> queue);
}

TEST(TEST_BQUEUE, METHOD_PUSH)
{
    ptl::bqueue<int32_t> queue;
    queue.push(10);
    return;
}

TEST(TEST_BQUEUE, METHOD_POP)
{
    ptl::bqueue<int32_t> queue;
    queue.push(10);
    ASSERT_EQ(queue.pop(), 10);
}