//
// Created by marek on 11.11.2022.
//

#include "Tree.h"
#include <vector>

using namespace std;

class Tree {
private:
    class Node {
    private:
        vector<Node> children;
        Node *parent;
        int metadata;

    public:
        Node() {
            metadata = 0;
            parent = NULL;
        };

        Node(Node *customParent) {
            parent = customParent;
            metadata = 0;
        };

        ~Node() {
            while (!children.empty())
                children.pop_back();
        };

        void setMetadata(int data) { metadata = data; };

        int getChildrenNumber() { return (children.size()); };

        void addNewChild() {
            Node newNode;
            newNode.parent = this;
            children.push_back(newNode);
        };

        Node *getChild(int position) {
            if (position < 0 || position > children.size()) {
                cout << INCORRECT_SIZE;
                return NULL;
            }
            return &children.at(position);
        };

        void print() { cout << " " << metadata; };

        void printElementsBelow() {
            print();
            if (!children.empty())
                for (int i = 0; i < children.size(); i++)
                    children.at(i).printElementsBelow();
        };

        void printElementsUp() {
            print();
            if (parent != NULL)
                parent->printElementsUp();
        };
    };

    Node root;

public:
    Tree();

    ~Tree() {

    };

    Node *getRoot() { return (&root); }

    void printTree() {
        root.printElementsBelow();
    };
};