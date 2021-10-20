#include <gtest/gtest.h>

#include "ptl/vector"

TEST(TEST_VECTOR, CONSTRUCTOR)
{
    ASSERT_NO_THROW(ptl::vector<int32_t> vector);
}

TEST(TEST_VECTOR, CONSTRUCTOR_WITH_SIZE_PARAMETER)
{
    ASSERT_NO_THROW(ptl::vector<int32_t> vector(10));
}

TEST(TEST_VECTOR, CONSTRUCTOR_COPY)
{
    ptl::vector<int32_t> vector_a(3);
    vector_a[0] = 0;
    vector_a[1] = 1;
    vector_a[2] = 2;

    ptl::vector<int32_t> vector_b(vector_a);

    // ASSERT_EQ(vector_a, vector_b);
}

TEST(TEST_VECTOR, OPERATOR_EQUATING)
{
    ptl::vector<int32_t> vector_a;
    vector_a.push_back(10);
    ptl::vector<int32_t> vector_b;
    vector_b.push_back(20);

    vector_a = vector_b;

    // ASSERT_EQ(vector_a, vector_b);
}

TEST(TEST_VECTOR, OPERATOR_SQUARE_BRAKETS)
{
    ptl::vector<int32_t> vector_a(1);

    vector_a[0] = 10;

    ASSERT_EQ(vector_a[0], 10);
}

TEST(TEST_VECTOR, METHOD_EMPTY)
{
    ptl::vector<int32_t> vector_a;

    vector_a.push_back(10);
    vector_a.pop_back();

    ASSERT_TRUE(vector_a.empty());
}

TEST(TEST_VECTOR, METHOD_SIZE)
{
    ptl::vector<int32_t> vector_a;

    vector_a.push_back(10);

    ASSERT_EQ(vector_a.size(), 1);
}

TEST(TEST_VECTOR, METHOD_CAPACITY)
{
    ptl::vector<int32_t> vector_a(10);

    ASSERT_EQ(vector_a.size(), 10);
}

TEST(TEST_VECTOR, METHOD_PUSH_BACK)
{
    ptl::vector<int32_t> vector_a;

    vector_a.push_back(10);

    ASSERT_EQ(vector_a[0], 10);
}

TEST(TEST_VECTOR, METHOD_PUSH_BACK_ASYNC)
{
    ptl::vector<int32_t> vector_a;

    auto future = vector_a.push_back_async(10);
    future.wait();

    ASSERT_EQ(vector_a[0], 10);
}

TEST(TEST_VECTOR, METHOD_POP_BACK)
{
    ptl::vector<int32_t> vector_a;

    vector_a.push_back(10);
    vector_a.pop_back();

    ASSERT_EQ(vector_a.size(), 0);
}

TEST(TEST_VECTOR, METHOD_RESIZE)
{
    ptl::vector<int32_t> vector_a(5);

    vector_a.resize(10);

    ASSERT_EQ(vector_a.capacity(), 10);
}