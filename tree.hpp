#ifndef TREE_H
#define TREE_H

#include "node.hpp"

#include <deque>
#include <string_view>

namespace tree {
    void printPreorder(node::Node*);
    void printInorder(node::Node*);
    void printPostorder(node::Node*);

    node::Node* buildTree(std::deque<std::string_view>);
}

#endif  // TREE_H