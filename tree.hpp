#ifndef TREE_H
#define TREE_H

#include "node.hpp"

#include <deque>
#include <string>

namespace tree {

    node::Node* buildTree(std::deque<std::string>);

    void printPreorder(node::Node*, int);
    void printInorder(node::Node*, int);
    void printPostorder(node::Node*, int);

    node::Node* insert(std::string, node::Node*);

} //namespace tree

#endif  // TREE_H