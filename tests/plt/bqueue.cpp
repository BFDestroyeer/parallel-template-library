#include <gtest/gtest.h>
#include <omp.h>

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

TEST(BENCHMARK_BQUEUE, METHOD_PUSH)
{
    for (int j = 1; j <= 8; j++)
    {
        ptl::bqueue<int32_t> queue;
        auto begin = omp_get_wtime();
        omp_set_num_threads(j);
#pragma omp parallel default(none), shared(j, queue, std::cout)
        for (size_t i = 0; i < 100000; i++)
        {
            queue.push(0);
        }
        auto end = omp_get_wtime();
        std::cout << "BENCHMARK_BQUEUE"
                  << ":"
                  << "METHOD_PUSH"
                  << " " << "[" << j << "]"
                  << " " << end - begin << std::endl;
    }
}

TEST(BENCHMARK_BQUEUE, METHOD_POP)
{
    for (int j = 1; j <= 16; j++)
    {
        ptl::bqueue<int32_t> queue;
        for (size_t i = 0; i < 100000; i++)
        {
            queue.push(0);
        }
        auto begin = omp_get_wtime();
        omp_set_num_threads(j);
#pragma omp parallel default(none), shared(j, queue, std::cout)
        for (size_t i = 0; i < 100000; i++)
        {
            queue.pop();
        }
        auto end = omp_get_wtime();
        std::cout << "BENCHMARK_BQUEUE"
                  << ":"
                  << "METHOD_POP"
                  << " " << "[" << j << "]"
                  << " " << end - begin << std::endl;
    }
}