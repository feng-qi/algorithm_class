#include <gtest/gtest.h>
#include "QuickMedian.h"

TEST(QuickMedianTest, Basic) {
    QuickMedian qm;

    qm.add_number(1);
    ASSERT_EQ(qm.get_median(), 1);
    qm.add_number(5);
    ASSERT_EQ(qm.get_median(), 3);
    qm.add_number(3);
    qm.dump_heap();
    ASSERT_EQ(qm.get_median(), 3);
    qm.add_number(10);
    ASSERT_EQ(qm.get_median(), 4);
    qm.add_number(4);
    ASSERT_EQ(qm.get_median(), 4);
}
