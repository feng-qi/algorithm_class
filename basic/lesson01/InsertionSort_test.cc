#include <gtest/gtest.h>
#include "InsertionSort.h"

#include <algorithm>
#include <random>

template <typename T>
void fill_vector(T& v) {
    std::generate(v.begin(), v.end(), [](){
            static std::mt19937 generator(std::random_device{}());
            static std::uniform_int_distribution<> dist(-500, 100);
            return dist(generator);
        });
}

TEST(InsertionSortTest, Simple) {
    const int SIZE = 100;
    std::vector<int> vals1(SIZE);
    fill_vector(vals1);
    std::vector<int> vals2(vals1);

    insertion_sort(vals1);
    std::sort(vals2.begin(), vals2.end()); // use std::sort as a comparator

    ASSERT_EQ(vals1, vals2);
}

TEST(InsertionSortTest2, Simple) {
    const int SIZE = 100;
    std::vector<int> vals1(SIZE);
    fill_vector(vals1);
    std::vector<int> vals2(vals1);

    insertion_sort2(vals1);
    std::sort(vals2.begin(), vals2.end()); // use std::sort as a comparator

    ASSERT_EQ(vals1, vals2);
}
