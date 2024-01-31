#ifndef NODE_H
#define NODE_H

#include <string>

namespace node {

    class Node {
        //All these gets might be useless. If you return a pointer from a get, you typically want it to be immutable (const).
        //However, in order to assign it to the tempNode in tree.cpp, it cannot return a const because the types are incompatible
        public:
            inline Node(std::string val) {
                data = val;
                leftChild = NULL;
                rightChild = NULL;
                middleChild = NULL;
            }

            Node* getLeftChild() {
                return leftChild;
            }

            void setLeftChild(std::string val) {
                leftChild = new Node(val);
            }

            Node* getRightChild() {
                return rightChild;
            }

            void setRightChild(std::string val) {
                rightChild = new Node(val);
            }

            Node* getMiddleChild() {
                return middleChild;
            }

            void setMiddleChild(std::string val) {
                middleChild = new Node(val);
            }

            const std::string getData() {
                return data;
            }

        private:
            std::string data;
            Node* leftChild;
            Node* rightChild;
            Node* middleChild;
    };

};  // namespace node

#endif  // NODE_H