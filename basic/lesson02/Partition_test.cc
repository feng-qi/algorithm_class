#include "Partition.h"
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

template <typename T>
void print_vector(const T& v, int item_per_line = 0) {
    if (!item_per_line)
        item_per_line = v.size();
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << ((i+1) % item_per_line ? '\t' : '\n');
}

TEST(Partition2Test, Basic) {
    std::vector<int> v{9,8,4,6,3,7,2,1,5};

    partition2(v);
    print_vector(v);

    ASSERT_LT(v[0], 5);
    ASSERT_LT(v[1], 5);
    ASSERT_LT(v[2], 5);
    ASSERT_LT(v[3], 5);

    ASSERT_EQ(v[4], 5);

    ASSERT_GT(v[5], 5);
    ASSERT_GT(v[6], 5);
    ASSERT_GT(v[7], 5);
    ASSERT_GT(v[8], 5);
}

TEST(Partition3Test, Basic) {
    std::vector<int> v{9,8,5,4,6,5,3,7,5,2,1,5};

    partition3(v);
    print_vector(v);

    ASSERT_LT(v[0], 5);
    ASSERT_LT(v[1], 5);
    ASSERT_LT(v[2], 5);
    ASSERT_LT(v[3], 5);

    ASSERT_EQ(v[4], 5);
    ASSERT_EQ(v[5], 5);
    ASSERT_EQ(v[6], 5);
    ASSERT_EQ(v[7], 5);

    ASSERT_GT(v[ 8], 5);
    ASSERT_GT(v[ 9], 5);
    ASSERT_GT(v[10], 5);
    ASSERT_GT(v[11], 5);
}
