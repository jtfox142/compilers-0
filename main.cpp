#include <iostream>
#include <vector>
#include <string_view>
#include <string>
#include <stdexcept>
#include <fstream>
//#include "node.h"
//#include "tree.h"

int main(int argc, char* argv[]) {
    // process command line arguments first and error if improper
    // if filename given, make sure file is readable, error otherwise
    // set up keyboard processing so that below this point there is only one version of the code

    //Holds each individual word prior to being placed into the tree.
    std::vector<std::string_view> preTreeInput;

    std::string fileName;

    //If there are no provided args, initiate place user input into a temporary file
    if(argc <= 1) {
        static std::ofstream defaultFile;
        fileName = "default.txt";
        defaultFile.open(fileName, std::ios::out);

        std::string userInput;
        std::cout << "Please enter your input: ";
        std::cin >> userInput;

        defaultFile << userInput;
        defaultFile.close();

        std::cout << "\nDefault file has received input.\n";
    }
    else {
        std::string fileName = argv[1];
    }

    try {
        readFromFile(fileName, &preTreeInput);
    } catch(const std::exception& ex) {
        std::cerr << ex.what() << '\n';
    }
    
    for(const auto& arg : args) {
        node::node_t *root = tree::buildTree(file);
    }

    tree::printPreorder(root);
    tree::printInorder(root);
    tree::printPostorder(root);

    return 0;
}

void readFromFile(std::string_view filename, std::vector<std::string_view>* input) {
    static std::ifstream inputFile (filename);
    std::string word;

    if(inputFile.is_open()) {
        while(!inputFile.eof()) {
            //Not sure I need to do this every time, but the files should be small enough that the extra overhead will not matter
            if(inputFile.bad() || inputFile.fail()) {
                throw std::runtime_error("ERROR: bad file read");
            }

            inputFile >> word;
            input->push_back(word);
        }
    }
    else {
        throw std::runtime_error("ERROR: could not open file");
    }

    std::cout << "File read complete. preTreeInput vector has been filled";
}