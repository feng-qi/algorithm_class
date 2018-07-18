#include <gtest/gtest.h>
#include <memory>

struct Node {
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    int value;

    Node(std::shared_ptr<Node> left = nullptr, std::shared_ptr<Node> right = nullptr, int value = 0)
        : left(left), right(right), value(value) {}
};

struct ReturnData {
    int max_dist;
    int height;

    ReturnData(int max_dist, int height) : max_dist(max_dist), height(height) {}
};

ReturnData process(std::shared_ptr<Node> root) {
    if (root == nullptr)
        return ReturnData(0, 0);
    ReturnData left  = process(root->left);
    ReturnData right = process(root->right);
    int height = std::max(left.height, right.height) + 1;
    int max_dist = std::max(left.height + right.height + 1,
                            std::max(left.max_dist, right.max_dist));
    return ReturnData(max_dist, height);
}

int max_distance(std::shared_ptr<Node> root) {
    return process(root).max_dist;
}

TEST(MaxDistanceTest, Basic) {
    auto n0 = std::make_shared<Node>();
    auto n1 = std::make_shared<Node>();
    auto n2 = std::make_shared<Node>();
    auto n3 = std::make_shared<Node>();

    n2->left = n1;
    n2->right = n3;
    n1->left = n0;

    ASSERT_EQ(max_distance(n2), 4);
}

TEST(MaxDistanceTest, Left) {
    auto n0 = std::make_shared<Node>();
    auto n1 = std::make_shared<Node>();
    auto n2 = std::make_shared<Node>();
    auto n3 = std::make_shared<Node>();
    auto n4 = std::make_shared<Node>();
    auto n5 = std::make_shared<Node>();

    n1->left  = n0;
    n3->left  = n2;
    n4->left  = n1;
    n4->right = n3;
    n5->left  = n4;

    ASSERT_EQ(max_distance(n5), 5);
}

TEST(MaxDistanceTest, Right) {
    auto n0 = std::make_shared<Node>();
    auto n1 = std::make_shared<Node>();
    auto n2 = std::make_shared<Node>();
    auto n3 = std::make_shared<Node>();
    auto n4 = std::make_shared<Node>();
    auto n5 = std::make_shared<Node>();
    auto n6 = std::make_shared<Node>();
    auto n7 = std::make_shared<Node>();

    n1->left  = n0;
    n3->left  = n2;
    n4->left  = n1;
    n4->right = n3;
    n5->left  = n4;
    n6->right = n5;
    n7->right = n6;

    ASSERT_EQ(max_distance(n7), 6);
}
