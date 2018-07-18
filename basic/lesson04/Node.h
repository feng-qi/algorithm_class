#ifndef NODE_H
#define NODE_H

#include <memory>

struct Node {
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    int value;

    Node(std::shared_ptr<Node> left = nullptr,
         std::shared_ptr<Node> right = nullptr,
         int value = 0)
        : left(left), right(right), value(value) {}
};


#endif /* NODE_H */
