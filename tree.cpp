#include "node.hpp"
#include "tree.hpp"

#include <iostream>
#include <iomanip>
#include <stdexcept>

node::Node* buildTree(std::deque<std::string_view> preTreeInput) {
    node::Node* root = new node::Node(preTreeInput.front());
    preTreeInput.pop_front();

    //Should never happen. Should, not could.
    if(root == NULL) {
        throw std::runtime_error("ERROR: Input processing error. Root of the tree is null.");
    }

    //I know I could just use "auto" in a for loop declaration, but this helps me visualize
    std::deque<std::string_view>::iterator iterator;

    for(iterator = preTreeInput.begin(); iterator != preTreeInput.end(); iterator++) {
        //temporary node for traversal
        static node::Node* tempNode = root;

        //Find where the new node should go
        while(tempNode != NULL) {
            //Get the value that the current node is holding
            std::string_view tempData = tempNode->getData();

            //Compare the new value to the current value
            if((*iterator).at(0) < tempData.at(0)) {
                tempNode = tempNode->getLeftChild();
            }
            else if((*iterator).at(0) > tempData.at(0)) {
                tempNode = tempNode->getRightChild();
            }
            else if((*iterator).at(0) == tempData.at(0)) {
                tempNode = tempNode->getMiddleChild();
            }
        } 

        //If the while loop is broken, then the tempNode is at a NULL address. This is where the new node should go
        tempNode = new node::Node(*iterator);
    }

    return root;
}

//root, left, middle, right
static void printPreorder(node::Node *root, int level) {
    if (root==NULL) return;

    //TODO Change 9 to a variable or something.
    std::cout << std::setw(level * 2) << level << std::setw(9) << root->getData() << std::endl;

    printPreorder(root->getLeftChild(), level+1);
    printPreorder(root->getRightChild(), level+1);
}

//left, root (taking you down middle), right
void tree::printInorder(node::Node* root, int level) {

}

//left, middle, right, root
void tree::printPostorder(node::Node* root, int level) {

}

