#ifndef NODE_H
#define NODE_H

#include <string_view>

namespace node {

    class Node {
        public:
            Node(std::string_view val) {
                *data = val;
                leftChild = NULL;
                rightChild = NULL;
                middleChild = NULL;
            }

            //When returning a pointer from a getter function, it should be immutable (const)
            const Node* getLeftChild() {
                return leftChild;
            }

            void setLeftChild(std::string_view val) {
                leftChild = new Node(val);
            }

            const Node* getRightChild() {
                return rightChild;
            }

            void setRightChild(std::string_view val) {
                rightChild = new Node(val);
            }

            const Node* getMiddleChild() {
                return middleChild;
            }

            void setMiddleChild(std::string_view val) {
                middleChild = new Node(val);
            }

        private:
            std::string_view* data;
            Node* leftChild;
            Node* rightChild;
            Node* middleChild;
    };

};  // namespace node

#endif  // NODE_H