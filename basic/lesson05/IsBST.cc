#include "../lesson04/Node.h"
#include <limits>
#include <gtest/gtest.h>

struct ReturnData {
    bool isBST;
    int min;
    int max;
    ReturnData(bool isBST, int min, int max) : isBST(isBST), min(min), max(max) {}
};

inline bool operator==(const ReturnData& lhs, const ReturnData& rhs) {
    return lhs.isBST == rhs.isBST && lhs.min == rhs.min && lhs.max == rhs.max;
}

ReturnData is_bst(std::shared_ptr<Node> root) {
    if (root == nullptr)
        return {true, std::numeric_limits<int>::max(), std::numeric_limits<int>::lowest()};
    auto left  = is_bst(root->left);
    auto right = is_bst(root->right);
    bool is_search_tree = left.isBST && right.isBST
        && left.max    < root->value
        && root->value < right.min;
    return ReturnData(is_search_tree,
                      std::min(root->value, std::min(left.min, right.min)),
                      std::max(root->value, std::max(left.max, right.max)));
}

TEST(IsBST, Basic) {
    ASSERT_EQ(is_bst(nullptr),
              ReturnData(true, std::numeric_limits<int>::max(), std::numeric_limits<int>::lowest()));
}

TEST(IsBST, Balanced) {
    auto n0 = std::make_shared<Node>(nullptr, nullptr, 0);
    auto n1 = std::make_shared<Node>(nullptr, nullptr, 1);
    auto n2 = std::make_shared<Node>(nullptr, nullptr, 2);
    auto n3 = std::make_shared<Node>(nullptr, nullptr, 3);

    n2->left = n1;
    n2->right = n3;
    n1->left = n0;

    ASSERT_EQ(is_bst(n2), ReturnData(true,0,3));
}

TEST(IsBST, Unbalanced) {
    auto n0 = std::make_shared<Node>(nullptr, nullptr, 0);
    auto n1 = std::make_shared<Node>(nullptr, nullptr, 1);
    auto n2 = std::make_shared<Node>(nullptr, nullptr, 2);
    auto n3 = std::make_shared<Node>(nullptr, nullptr, 3);
    // auto n4 = std::make_shared<Node>(nullptr, nullptr, 4);

    n0->left = n1;
    n0->right = n2;
    n1->left = n3;
    // n3->left = n4;

    ASSERT_EQ(is_bst(n0), ReturnData(false,0,3));
}
