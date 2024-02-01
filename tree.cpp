#include "node.hpp"
#include "tree.hpp"

#include <iostream>
#include <iomanip>
#include <stdexcept>

node::Node* tree::buildTree(std::deque<std::string> preTreeInput, node::Node* root) {
    //Compiler won't allow 'auto'
    std::deque<std::string>::iterator iterator;

    std::cout << "Beginning to build the tree." << std::endl;

    //Iterator points to one word of input at a time
    for(iterator = preTreeInput.begin(); iterator != preTreeInput.end(); iterator++) {
        insert(*iterator, root);
    }

    return root;
}

//root, left, middle, right
void tree::printPreorder(node::Node *root, int level) {
    if(root == NULL) return;

    //TODO Change 9 to a variable or something.
    std::cout << std::setw(level * 2) << level << std::setw(9) << root->getData() << std::endl;

    printPreorder(root->getLeftChild(), level+1);
    printPreorder(root->getMiddleChild(), level+1);
    printPreorder(root->getRightChild(), level+1);
}

//left, root (taking you down middle), right
void tree::printInorder(node::Node* root, int level) {

}

//left, middle, right, root
void tree::printPostorder(node::Node* root, int level) {

}

//Inefficient, but it works. Would love to optimize later
void tree::insert(std::string word, node::Node* root) {
    std::cout << "Inserting " << word << " into the tree." << std::endl;
        
        //temporary nodes for traversing the tree
        node::Node* tempNodeOne = root;
        node::Node* tempNodeTwo = NULL;

        //Find where the new node should go
        while(tempNodeOne != NULL) {
            tempNodeTwo = tempNodeOne;
            //Get the value that the current node is holding
            std::string tempData = tempNodeOne->getData();
            std::cout << "TempData is " << tempData << std::endl;

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
            std::cout << word << " has been inserted on the left." << std::endl;
        }
        else if(word.at(0) == tempNodeTwo->getData().at(0)) {
            tempNodeTwo->setMiddleChild(word);
            std::cout << word << " has been inserted in the middle." << std::endl;
        }
        else if(word.at(0) > tempNodeTwo->getData().at(0)) {
            std::cout << word << " has been inserted on the right." << std::endl;
            tempNodeTwo->setRightChild(word);
        }
}