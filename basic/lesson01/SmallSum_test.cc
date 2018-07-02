#include <gtest/gtest.h>
#include "SmallSum.h"

TEST(MergeSortTest, Simple) {
    std::vector<int> vals1{1,3,4,2,5};

    int sum = small_sum(vals1);

    ASSERT_EQ(sum, 16);
}
