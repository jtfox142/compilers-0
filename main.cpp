#include <iostream>
#include <deque>
#include <string>
#include <stdexcept>
#include <fstream>
#include "node.hpp"
#include "tree.hpp"

//Function prototypes
void readFromFile(std::string, std::deque<std::string>*);
void printToTerminal(std::deque<std::string>);

int main(int argc, char* argv[]) {
    // process command line arguments first and error if improper
    // if filename given, make sure file is readable, error otherwise
    // set up keyboard processing so that below this point there is only one version of the code

    /*
    TODO
        * Pull input parsing out into its own file
            * Error upon bad input (like % or $) 
        * Tree functions
            * push traversals into files
    */

    //Holds each individual word prior to being placed into the tree.
    std::deque<std::string> preTreeInput;

    std::string fileName;

    //If there are no provided args, initiate place user input into a temporary file
    //The first argument should always be the path to the program
    if(argc <= 1) {
        std::ofstream defaultFile;
        fileName = "default.txt";
        //Need to convert string to c string for .open() function call
        defaultFile.open(fileName.c_str(), std::ios::out | std::ios::trunc);

        std::string userInput;
        std::cout << "Please enter your input: ";
        std::getline(std::cin, userInput);

        defaultFile << userInput;
        defaultFile.close();

        std::cout << "\nDefault file has received input.\n";
    }
    else { //Otherwise, attempt to use the filename provided to the executable
        std::string fileName = argv[1];
        std::cout << "Filename: " << fileName << std::endl;
    }

    try {
        readFromFile(fileName, &preTreeInput);
    } catch(const std::exception& ex) {
        std::cerr << ex.what() << '\n';
        return EXIT_FAILURE;
    }
    
    //TODO for testing purposes only. Delete later.
    printToTerminal(preTreeInput);

    //Initialize the root node
    node::Node *root = new node::Node(preTreeInput.front());
    preTreeInput.pop_front();

    tree::buildTree(preTreeInput, root);
    
    std::cout << "\nPrinting preorder tree traversal." << std::endl;
    tree::printPreorder(root, 0);

    std::cout << "\nPrinting inorder tree traversal." << std::endl;
    tree::printInorder(root, 0);

    std::cout << "\nPrinting postorder tree traversal." << std::endl;
    tree::printPostorder(root, 0);

    return 0;
}

//Pushes file data onto a deque, which is then used to build the tree
void readFromFile(std::string fileName, std::deque<std::string>* input) {
    std::ifstream inputFile (fileName.c_str());
    std::string word;

    if(inputFile.is_open()) {
        std::cout << "File " << fileName << " is open." << std::endl;
        while(!inputFile.eof()) {
            //Not sure if I need to do this every time, but the files should be small enough that the extra overhead will not matter
            if(inputFile.fail() || inputFile.bad()) {
                throw std::runtime_error("ERROR: bad file read");
            }

            inputFile >> word;
            input->push_back(word);
        }
    }
    else {
        throw std::runtime_error("ERROR: could not open file. Possible bad file name.");
    }

    inputFile.close();
    std::cout << "File read complete. preTreeInput deque has been filled." << std::endl;
}

//For testing purposes only, delete later.
void printToTerminal(std::deque<std::string> preTreeInput) {
    std::cout << "Printing preTreeInput to terminal." << std::endl;

    std::deque<std::string>::iterator iterator;

    for(iterator = preTreeInput.begin(); iterator != preTreeInput.end(); iterator++)
        std::cout << *iterator << std::endl;
}