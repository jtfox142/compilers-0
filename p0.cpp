#include "node.hpp"
#include "tree.hpp"
#include "scanner.hpp"

#include <iostream>
#include <deque>
#include <string>
#include <stdexcept>
#include <fstream>

int main(int argc, char* argv[]) {
    //Process any command line input and intake keyboard input, if necessary 
    scanner::setFileName(argc, argv);

    //Try to open the file and read the data onto a deque for processing
    try {
        scanner::readFromFile();
    } catch(const std::exception& ex) {
        std::cerr << ex.what() << '\n';
        return 1;
    }

    std::deque<std::string> preTreeInput = scanner::getUserInput();
    
    //Initialize the root node
    node::Node *root = new node::Node(preTreeInput.front());
    preTreeInput.pop_front();
    
    tree::buildTree(preTreeInput, root);
    
    tree::outputTrees(root, scanner::getFileName());

    return 0;
}