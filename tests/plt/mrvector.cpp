#include <gtest/gtest.h>
#include <omp.h>

#include "ptl/mrvector"

TEST(TEST_MRVECTOR, CONSTRUCTOR_WITH_SIZE_PARAMETER)
{
    ASSERT_NO_THROW(ptl::mrvector<int32_t> vector(10));
}

TEST(TEST_MRVECTOR, METHOD_WRITE)
{
    ptl::mrlock lock(16);
    lock.random_access_lock(1);
    auto test = lock.random_access_lock(2);
    lock.unlock(test);

    ptl::mrvector<int32_t> vector_a(1);

    ASSERT_NO_THROW(vector_a.write(0, 2));
}

TEST(TEST_MRVECTOR, METHOD_AT)
{
    ptl::mrvector<int32_t> vector_a(1);

    vector_a.write(0, 2);

    ASSERT_EQ(vector_a.at(0), 2);
}

TEST(BENCHMARK_MRVECTOR, METHOD_WRITE)
{
    for (int j = 1; j <= 8; j++)
    {
        ptl::mrvector<int32_t> vector(32);
        auto begin = omp_get_wtime();
        omp_set_num_threads(j);
#pragma omp parallel for default(none), shared(j, vector)
        for (size_t i = 0; i < 1000000; i++)
        {
            vector.write(rand() % 32, 0);
        }
        auto end = omp_get_wtime();
        std::cout << "BENCHMARK_MRVECTOR"
                  << ":"
                  << "METHOD_WRITE"
                  << " "
                  << "[" << j << "]"
                  << " " << end - begin << std::endl;
    }
}

TEST(BENCHMARK_MRVECTOR, METHOD_PUSH_BACK)
{
    for (int j = 1; j <= 8; j++)
    {
        ptl::mrvector<int32_t> vector(0, 100000);
        auto begin = omp_get_wtime();
        omp_set_num_threads(j);
#pragma omp parallel for default(none), shared(j, vector)
        for (size_t i = 0; i < 100000; i++)
        {
            vector.push_back(0);
        }
        auto end = omp_get_wtime();
        std::cout << "BENCHMARK_MRVECTOR"
                  << ":"
                  << "METHOD_PUSH_BACK"
                  << " "
                  << "[" << j << "]"
                  << " " << end - begin << std::endl;
    }
}