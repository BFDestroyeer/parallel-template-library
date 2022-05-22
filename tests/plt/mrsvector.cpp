#include <gtest/gtest.h>
#include <omp.h>

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

TEST(BENCHMARK_MRSVECTOR, METHOD_WRITE)
{
    for (int j = 1; j <= 8; j++)
    {
        ptl::mrsvector<int32_t> vector(32);
        auto begin = omp_get_wtime();
        omp_set_num_threads(j);
#pragma omp parallel for default(none), shared(j, vector)
        for (size_t i = 0; i < 1000000; i++)
        {
            vector.write(rand() % 32, 0);
        }
        auto end = omp_get_wtime();
        std::cout << "BENCHMARK_MRSVECTOR"
                  << ":"
                  << "METHOD_WRITE"
                  << " "
                  << "[" << j << "]"
                  << " " << end - begin << std::endl;
    }
}

TEST(BENCHMARK_MRSVECTOR, METHOD_PUSH_BACK)
{
    for (int j = 1; j <= 8; j++)
    {
        ptl::mrsvector<int32_t> vector(1);
        auto begin = omp_get_wtime();
        omp_set_num_threads(j);
#pragma omp parallel for default(none), shared(j, vector)
        for (size_t i = 0; i < 100000; i++)
        {
            vector.push_back(0);
        }
        auto end = omp_get_wtime();
        std::cout << "BENCHMARK_MRSVECTOR"
                  << ":"
                  << "METHOD_PUSH_BACK"
                  << " "
                  << "[" << j << "]"
                  << " " << end - begin << std::endl;
    }
}