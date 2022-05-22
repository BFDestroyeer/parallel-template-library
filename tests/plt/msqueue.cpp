#include <gtest/gtest.h>
#include <omp.h>

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

TEST(BENCHMARK_MSQUEUE, METHOD_PUSH)
{
    for (int j = 1; j <= 8; j++)
    {
        ptl::msqueue<int32_t> queue;
        auto begin = omp_get_wtime();
        omp_set_num_threads(j);
#pragma omp parallel for default(none), shared(j, queue)
        for (size_t i = 0; i < 1000000; i++)
        {
            queue.push(0);
        }
        auto end = omp_get_wtime();
        std::cout << "BENCHMARK_MSQUEUE"
                  << ":"
                  << "METHOD_PUSH"
                  << " "
                  << "[" << j << "]"
                  << " " << end - begin << std::endl;
    }
}

TEST(BENCHMARK_MSQUEUE, METHOD_POP)
{
    for (int j = 1; j <= 8; j++)
    {
        ptl::msqueue<int32_t> queue;
        for (size_t i = 0; i < 1000000; i++)
        {
            queue.push(0);
        }
        auto begin = omp_get_wtime();
        omp_set_num_threads(j);
#pragma omp parallel for default(none), shared(j, queue)
        for (size_t i = 0; i < 1000000; i++)
        {
            queue.pop();
        }
        auto end = omp_get_wtime();
        std::cout << "BENCHMARK_MSQUEUE"
                  << ":"
                  << "METHOD_POP"
                  << " "
                  << "[" << j << "]"
                  << " " << end - begin << std::endl;
    }
}

TEST(BENCHMARK_MSQUEUE, METHOD_PUSH_AND_POP)
{
    for (int j = 1; j <= 8; j++)
    {
        ptl::msqueue<int32_t> queue;
        for (size_t i = 0; i < 1000000; i++)
        {
            queue.push(0);
        }
        auto begin = omp_get_wtime();
        omp_set_num_threads(j);
#pragma omp parallel for default(none), shared(j, queue)
        for (size_t i = 0; i < 1000000; i++)
        {
            if (rand() % 2 == 0)
            {
                queue.push(0);
            }
            else
            {
                queue.pop();
            }
        }
        auto end = omp_get_wtime();
        std::cout << "BENCHMARK_MSQUEUE"
                  << ":"
                  << "METHOD_PUSH_AND_POP"
                  << " "
                  << "[" << j << "]"
                  << " " << end - begin << std::endl;
    }
}