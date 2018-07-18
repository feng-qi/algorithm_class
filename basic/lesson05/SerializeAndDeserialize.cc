#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
#include <deque>
#include <string>
#include <sstream>
#include <gtest/gtest.h>
#include "../lesson04/Node.h"

using std::string;
using std::queue;
using std::to_string;
using std::shared_ptr;

string serialize_pre(shared_ptr<Node> root) {
    if (root == nullptr)
        return "# ";
    string val = to_string(root->value) + ' ';
    val += serialize_pre(root->left);
    val += serialize_pre(root->right);
    return val;
}

shared_ptr<Node> deserialize_pre(queue<string>& q) {
    string val = q.front(); q.pop();
    if (val == "#")
        return nullptr;

    auto node = std::make_shared<Node>();
    node->value = std::stod(val);
    node->left  = deserialize_pre(q);
    node->right = deserialize_pre(q);
    return node;
}

TEST(SerializePre, Basic) {
    auto n0 = std::make_shared<Node>(nullptr, nullptr, 0);
    auto n1 = std::make_shared<Node>(nullptr, nullptr, 1);
    auto n2 = std::make_shared<Node>(nullptr, nullptr, 22);
    auto n3 = std::make_shared<Node>(nullptr, nullptr, 333);

    n2->left  = n1;
    n2->right = n3;
    n1->left  = n0;

    ASSERT_EQ(serialize_pre(n2), "22 1 0 # # # 333 # # ");
}

TEST(DeserializePre, Basic) {
    std::istringstream iss("22 1 0 # # # 333 # # ");
    std::deque<string> dq{std::istream_iterator<string>(iss), std::istream_iterator<string>{}};
    queue<string> q(dq);
    shared_ptr<Node> root = deserialize_pre(q);

    ASSERT_EQ(serialize_pre(root), "22 1 0 # # # 333 # # ");

    ASSERT_EQ(root->value, 22);
    ASSERT_EQ(root->left->value, 1);
    ASSERT_EQ(root->right->value, 333);
    ASSERT_EQ(root->left->left->value, 0);
}
