#include "node.hpp"
#include "tree.hpp"

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <fstream>

node::Node* tree::buildTree(std::deque<std::string> preTreeInput, node::Node* root) {
    //Compiler won't allow 'auto'
    std::deque<std::string>::iterator iterator;

    std::cout << "Building the tree." << std::endl;

    //Iterator points to one word of input at a time
    for(iterator = preTreeInput.begin(); iterator != preTreeInput.end(); iterator++) {
        insert(*iterator, root);
    }

    return root;
}

void tree::outputTrees(node::Node *root, std::string fileName) {
    std::string outputFilePretext;

    //If the user didn't supply a file in the command line, then all output should go to
    //a file called "output.xxx".
    if(fileName == "default.txt") {
        outputFilePretext = "output";
    }
    else {
        //This strips the file type from the end of the file name.
        int pos = fileName.find(".");
        outputFilePretext = fileName.substr(0, pos);
    }
    
    std::string outputFileName;
    std::ofstream outputFile;

    //Block scopes are here to easily reset the file type of outputFileName.
    //Easier than searching through the string to find the '.' and replacing what follows (twice).
    //Nothing else inside is really stateful, so it should be fine. Just void functions.
    {
        outputFileName = outputFilePretext + ".preorder";
        outputFile.open(outputFileName.c_str(), std::ios::out | std::ios::app);

        std::cout << "\nPrinting preorder tree traversal into " << outputFileName << std::endl;
        tree::printPreorder(root, 0, outputFile);

        outputFile.close();
    }

    {
        outputFileName = outputFilePretext + ".inorder";
        outputFile.open(outputFileName.c_str(), std::ios::out | std::ios::app);

        std::cout << "\nPrinting inorder tree traversal into " << outputFileName << std::endl;
        tree::printInorder(root, 0, outputFile);

        outputFile.close();
    }

    {
        outputFileName = outputFilePretext + ".postorder";
        outputFile.open(outputFileName.c_str(), std::ios::out | std::ios::app);

        std::cout << "\nPrinting postorder tree traversal into " << outputFileName << std::endl;
        tree::printPostorder(root, 0, outputFile);

        outputFile.close();
    }
}

//root, left, middle, right
void tree::printPreorder(node::Node *root, int level, std::ofstream &file) {
    if(root == NULL) return;

    std::cout << std::setw(level * 2) << level << std::setw(12) << root->getData() << std::endl;
    file << std::setw(level * 2) << level << std::setw(12) << root->getData() << std::endl;

    printPreorder(root->getLeftChild(), level+1, file);
    printPreorder(root->getMiddleChild(), level+1, file);
    printPreorder(root->getRightChild(), level+1, file);
}

//left, root (taking you down middle), right
void tree::printInorder(node::Node* root, int level, std::ofstream &file) {
    if(root == NULL) return;

    printInorder(root->getLeftChild(), level+1, file);
    std::cout << std::setw(level * 2) << level << std::setw(12) << root->getData() << std::endl;
    file << std::setw(level * 2) << level << std::setw(12) << root->getData() << std::endl;

    printInorder(root->getMiddleChild(), level+1, file);
    printInorder(root->getRightChild(), level+1, file);
}

//left, middle, right, root
void tree::printPostorder(node::Node* root, int level, std::ofstream &file) {
    if(root == NULL) return;

    printPostorder(root->getLeftChild(), level+1, file);
    printPostorder(root->getMiddleChild(), level+1, file);
    printPostorder(root->getRightChild(), level+1, file);

    std::cout << std::setw(level * 2) << level << std::setw(12) << root->getData() << std::endl;
    file << std::setw(level * 2) << level << std::setw(12) << root->getData() << std::endl;
}

//Inefficient, but it works. Would love to optimize later
void tree::insert(std::string word, node::Node* root) {
    //std::cout << "Inserting " << word << " into the tree." << std::endl;
        
    //temporary nodes for traversing the tree
    node::Node* tempNodeOne = root;
    node::Node* tempNodeTwo = NULL;

    //Find where the new node should go
    while(tempNodeOne != NULL) {
        tempNodeTwo = tempNodeOne;
        //Get the value that the current node is holding
        std::string tempData = tempNodeOne->getData();

        //Compare the new value to the current value
        if(word.at(0) < tempData.at(0)) {
            tempNodeOne = tempNodeOne->getLeftChild();
        }
        else if(word.at(0) > tempData.at(0)) {
            tempNodeOne = tempNodeOne->getRightChild();
        }
        else if(word.at(0) == tempData.at(0)) {
            tempNodeOne = tempNodeOne->getMiddleChild();
        }
    } 

    //If the while loop is broken, then the tempNodeOne is at a NULL address. This is where the new node should go
    if(word.at(0) < tempNodeTwo->getData().at(0)) {
        tempNodeTwo->setLeftChild(word);
        //std::cout << word << " has been inserted on the left." << std::endl;
    }
    else if(word.at(0) == tempNodeTwo->getData().at(0)) {
        tempNodeTwo->setMiddleChild(word);
        //std::cout << word << " has been inserted in the middle." << std::endl;
    }
    else if(word.at(0) > tempNodeTwo->getData().at(0)) {
        std::cout << word << " has been inserted on the right." << std::endl;
        //tempNodeTwo->setRightChild(word);
    }
}