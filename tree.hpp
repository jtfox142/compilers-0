#ifndef TREE_H
#define TREE_H

#include "node.hpp"

#include <deque>
#include <string>

namespace tree {

    node::Node* tree::buildTree(std::deque<std::string>);

    void tree::printPreorder(node::Node*, int);
    void printInorder(node::Node*, int);
    void printPostorder(node::Node*, int);

} //namespace tree

#endif  // TREE_H