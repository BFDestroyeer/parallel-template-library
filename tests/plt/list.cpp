#include <omp.h>

#include <gtest/gtest.h>

#include "ptl/list"

TEST(TEST_LIST, CONSTRUCTOR)
{
    ASSERT_NO_THROW(ptl::list<int32_t> list);
}

TEST(TEST_LIST, CONSTRUCTOR_WITH_SIZE_PARAMETER)
{
    ASSERT_NO_THROW(ptl::list<int32_t> list_a(10));
}

TEST(TEST_LIST, METHOD_CLEAR)
{
    ptl::list<int32_t> list_a(10);
    list_a.clear();
    ASSERT_TRUE(list_a.empty());
}

TEST(TEST_LIST, METHOD_CLEAR_ASYNC)
{
    ptl::list<int32_t> list_a(10);
    auto future = list_a.clear_async();
    future.wait();
    ASSERT_TRUE(list_a.empty());
}

TEST(TEST_LIST, METHOD_PUSH_BACK)
{
    ptl::list<int32_t> list_a(15);
    list_a.push_back(10);
}

TEST(TEST_LIST, METHOD_UNIQUE)
{
    ptl::list<int32_t> list_a(10);
    list_a.unique();
}

// Benchmarks
TEST(BENCHMARK_LIST, CONSTRUCTOR_WITH_SIZE_PARAMETER)
{
    auto begin = omp_get_wtime();
    ptl::list<int32_t> list_a(1024 * 1024 * 4);
    auto end = omp_get_wtime();

    std::cout << "BENCHMARK_LIST"
              << ":"
              << "CONSTRUCTOR_WITH_SIZE_PARAMETER"
              << " " << end - begin << std::endl;
    ASSERT_TRUE(list_a.size() == 1024 * 1024 * 4);
}

TEST(BENCHMARK_LIST, METHOD_CLEAR)
{
    ptl::list<int32_t> list_a(1024 * 1024 * 4);
    ptl::list<int32_t> list_b(1024 * 1024 * 4);
    ptl::list<int32_t> list_c(1024 * 1024 * 4);

    auto begin = omp_get_wtime();
    list_a.clear();
    list_b.clear();
    list_c.clear();
    auto end = omp_get_wtime();

    std::cout << "BENCHMARK_LIST"
              << ":"
              << "METHOD_CLEAR"
              << " " << end - begin << std::endl;
    ASSERT_TRUE(list_a.empty());
    ASSERT_TRUE(list_b.empty());
    ASSERT_TRUE(list_c.empty());
}

TEST(BENCHMARK_LIST, METHOD_CLEAR_ASYNC)
{
    ptl::list<int32_t> list_a(1024 * 1024 * 4);
    ptl::list<int32_t> list_b(1024 * 1024 * 4);
    ptl::list<int32_t> list_c(1024 * 1024 * 4);

    auto begin = omp_get_wtime();
    auto future_a = list_a.clear_async();
    auto future_b = list_b.clear_async();
    auto future_c = list_c.clear_async();
    future_a.wait();
    future_b.wait();
    future_c.wait();
    auto end = omp_get_wtime();

    std::cout << "BENCHMARK_LIST"
              << ":"
              << "METHOD_CLEAR_ASYNC"
              << " " << end - begin << std::endl;
    ASSERT_TRUE(list_a.empty());
    ASSERT_TRUE(list_b.empty());
    ASSERT_TRUE(list_c.empty());
}

TEST(BENCHMARK_LIST, METHOD_UNIQUE)
{
    ptl::list<int32_t> list_a(1024 * 1024 * 4);
    ptl::list<int32_t> list_b(1024 * 1024 * 4);
    ptl::list<int32_t> list_c(1024 * 1024 * 4);

    auto begin = omp_get_wtime();
    list_a.unique();
    list_b.unique();
    list_c.unique();
    auto end = omp_get_wtime();

    std::cout << "BENCHMARK_LIST"
              << ":"
              << "METHOD_UNIQUE"
              << " " << end - begin << std::endl;
}

TEST(BENCHMARK_LIST, METHOD_UNIQUE_ASYNC)
{
    ptl::list<int32_t> list_a(1024 * 1024 * 4);
    ptl::list<int32_t> list_b(1024 * 1024 * 4);
    ptl::list<int32_t> list_c(1024 * 1024 * 4);

    auto begin = omp_get_wtime();
    auto future_a = list_a.unique_async();
    auto future_b = list_b.unique_async();
    auto future_c = list_c.unique_async();
    future_a.wait();
    future_b.wait();
    future_c.wait();
    auto end = omp_get_wtime();

    std::cout << "BENCHMARK_LIST"
              << ":"
              << "METHOD_UNIQUE_ASYNC"
              << " " << end - begin << std::endl;
}
