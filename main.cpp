#include "inputParsing.hpp"

#include <iostream>
#include <vector>
#include <string_view>
//#include "node.h"
//#include "tree.h"

int main(int argc, char* argv[]) {
    // process command line arguments first and error if improper
    // if filename given, make sure file is readable, error otherwise
    // set up keyboard processing so that below this point there is only one version of the code

    inputParsing::parse(argc, argv);

    for(const auto& arg : args) {
        node::node_t *root = tree::buildTree(file);
    }

    tree::printPreorder(root);
    tree::printInorder(root);
    tree::printPostorder(root);

    return 0;
}