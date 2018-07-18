#include "QuickSort.h"
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void print_vector(const T& v, int item_per_line = 0) {
    if (!item_per_line)
        item_per_line = v.size();
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << ((i+1) % item_per_line ? '\t' : '\n');
}

TEST(QuickSort2Test, Basic) {
    std::vector<int> v1{9,8,7,6,5,4,3,2,1};
    std::vector<int> v2(v1);

    quick_sort2(v1);
    // print_vector(v1);
    std::sort(v2.begin(), v2.end());

    ASSERT_EQ(v1, v2);
}

TEST(Partition3Test, Basic) {
    std::vector<int> v{9,8,5,4,6,5,3,7,5,2,1,5};

    partition3(v, 0, v.size()-1);
    // print_vector(v);

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

TEST(Partition3Test, Basic2) {
    std::vector<int> v{7,8,9,6};

    partition3(v, 0, v.size()-1);
    // print_vector(v);

    ASSERT_EQ(v[0], 6);
    ASSERT_GT(v[1], 6);
    ASSERT_GT(v[2], 6);
    ASSERT_GT(v[3], 6);
}

TEST(QuickSort3Test, Basic) {
    std::vector<int> v1{9,5,8,7,6,5,5,4,3,2,1,5};
    std::vector<int> v2(v1);

    quick_sort3(v1);
    // print_vector(v1);
    std::sort(v2.begin(), v2.end());

    ASSERT_EQ(v1, v2);
}

TEST(QuickSort3_Test, Basic) {
    std::vector<int> v1{9,5,8,7,6,5,5,4,3,2,1,5};
    std::vector<int> v2(v1);

    quick_sort3_(v1);
    // print_vector(v1);
    std::sort(v2.begin(), v2.end());

    ASSERT_EQ(v1, v2);
}
