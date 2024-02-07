#ifndef TREE_H
#define TREE_H

#include "node.hpp"

#include <deque>
#include <string>

namespace tree {
    
    node::Node* buildTree(std::deque<std::string>, node::Node*);
    void outputTrees(node::Node*, std::string);

    void printPreorder(node::Node*, int, std::ofstream&);
    void printInorder(node::Node*, int, std::ofstream&);
    void printPostorder(node::Node*, int, std::ofstream&);

    void insert(std::string, node::Node*);

} //namespace tree

#endif  // TREE_H