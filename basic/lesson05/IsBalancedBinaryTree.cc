#include "../lesson04/Node.h"
#include <tuple>
#include <cmath>
#include <gtest/gtest.h>

std::tuple<bool,int> is_balanced_binary_tree(std::shared_ptr<Node> root) {
    if (root == nullptr)
        return {true, 0};
    auto left = is_balanced_binary_tree(root->left);
    auto right = is_balanced_binary_tree(root->right);
    bool is_balanced = std::get<0>(left)
        && std::get<0>(right)
        && abs(std::get<1>(left) - std::get<1>(right)) < 2;
    return std::make_tuple(is_balanced, std::max(std::get<1>(left), std::get<1>(right)) + 1);
}

TEST(IsBalancedBinaryTree, Basic) {
    ASSERT_EQ(is_balanced_binary_tree(nullptr), std::make_tuple(true,0));
}

TEST(IsBalancedBinaryTree, Balanced) {
    auto n0 = std::make_shared<Node>(nullptr, nullptr, 0);
    auto n1 = std::make_shared<Node>(nullptr, nullptr, 1);
    auto n2 = std::make_shared<Node>(nullptr, nullptr, 2);
    auto n3 = std::make_shared<Node>(nullptr, nullptr, 3);

    n0->left = n1;
    n0->right = n2;
    n1->left = n3;

    ASSERT_EQ(is_balanced_binary_tree(n0), std::make_tuple(true,3));
}

TEST(IsBalancedBinaryTree, Unbalanced) {
    auto n0 = std::make_shared<Node>(nullptr, nullptr, 0);
    auto n1 = std::make_shared<Node>(nullptr, nullptr, 1);
    auto n2 = std::make_shared<Node>(nullptr, nullptr, 2);
    auto n3 = std::make_shared<Node>(nullptr, nullptr, 3);
    auto n4 = std::make_shared<Node>(nullptr, nullptr, 4);

    n0->left = n1;
    n0->right = n2;
    n1->left = n3;
    n3->left = n4;

    ASSERT_EQ(is_balanced_binary_tree(n0), std::make_tuple(false,4));
}
