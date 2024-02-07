#include <iostream>
#include <deque>
#include <string>
#include <stdexcept>
#include <fstream>
#include "node.hpp"
#include "tree.hpp"
#include "scanner.hpp"

//Function prototypes
void readFromFile(std::string, std::deque<std::string>*);
void printToTerminal(std::deque<std::string>);

int main(int argc, char* argv[]) {
    // process command line arguments first and error if improper
    // if filename given, make sure file is readable, error otherwise
    // set up keyboard processing so that below this point there is only one version of the code

    /*
    TODO
        * Input handling
            * Error upon bad input (like % or $) 
        * Tree functions
            * Change number outputs to char outputs
    */

    //Holds each individual word prior to being placed into the tree.

    scanner::setFileName(argc, argv);

    try {
        scanner::readFromFile();
    } catch(const std::exception& ex) {
        std::cerr << ex.what() << '\n';
        return EXIT_FAILURE;
    }

    std::deque<std::string> preTreeInput = scanner::getUserInput();
    
    //Initialize the root node
    node::Node *root = new node::Node(preTreeInput.front());
    preTreeInput.pop_front();

    tree::buildTree(preTreeInput, root);
    
    tree::outputTrees(root, scanner::getFileName());

    return 0;
}