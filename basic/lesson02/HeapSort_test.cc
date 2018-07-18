#include <vector>
#include <gtest/gtest.h>
#include "HeapSort.h"

TEST(HeapSortTest, Basic) {
    std::vector<int> v1{9,8,7,6,5,4,3,2,1};
    std::vector<int> v2(v1);

    heap_sort(v1);
    // print_vector(v1);
    std::sort(v2.begin(), v2.end());

    ASSERT_EQ(v1, v2);
}
