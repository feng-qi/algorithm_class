#include <memory>
#include <gtest/gtest.h>

using std::shared_ptr;

struct Node {
    shared_ptr<Node> left;
    shared_ptr<Node> right;
    shared_ptr<Node> parent;

    Node(shared_ptr<Node> left = nullptr,
         shared_ptr<Node> right = nullptr,
         shared_ptr<Node> parent = nullptr)
        : left(left), right(right), parent(parent) {}
};

shared_ptr<Node> get_most_left_node(shared_ptr<Node> node) {
    if (node == nullptr)
        return node;
    while (node->left != nullptr)
        node = node->left;
    return node;
}

shared_ptr<Node> successor_node(shared_ptr<Node> node) {
    if (node == nullptr)
        return nullptr;
    if (node->right != nullptr) {
        return get_most_left_node(node->right);
    } else {
        auto cur = node;
        auto parent = node->parent;
        while (parent && node == parent->right) {
            cur = parent;
            parent = parent->parent;
        }
        return parent;
    }
}

TEST(SuccessorNode, Basic) {
    auto n0 = std::make_shared<Node>();
    auto n1 = std::make_shared<Node>();
    auto n2 = std::make_shared<Node>();
    auto n3 = std::make_shared<Node>();
    auto n4 = std::make_shared<Node>();
    auto n5 = std::make_shared<Node>();

    n1->left   = n0;
    n0->parent = n1;

    n3->left   = n2;
    n2->parent = n3;

    n4->left   = n1;
    n1->parent = n4;

    n4->right  = n3;
    n3->parent = n4;

    n5->left   = n4;
    n4->parent = n5;

    ASSERT_EQ(successor_node(n4), n2);
}
