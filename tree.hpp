#ifndef TREE_H
#define TREE_H

#include "node.hpp"

#include <deque>
#include <string_view>

namespace tree {
    void printPreorder(node::Node*, int);
    void printInorder(node::Node*, int);
    void printPostorder(node::Node*, int);

    node::Node* buildTree(std::deque<std::string_view>);
}

#endif  // TREE_H