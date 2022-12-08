#include <iostream>
#include <vector>
#include "node.h"

using namespace std;

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

void treeTest() {
    Node root;
    root.addNewChild();
    root.addNewChild();
    root.getChild(0)->setMetadata(1);
    root.getChild(1)->setMetadata(2);
    root.getChild(0)->addNewChild();
    root.getChild(0)->addNewChild();
    root.getChild(0)->getChild(0)->setMetadata(11);
    root.getChild(0)->getChild(1)->setMetadata(12);
    root.getChild(1)->addNewChild();
    root.getChild(1)->addNewChild();
    root.getChild(1)->getChild(0)->setMetadata(21);
    root.getChild(1)->getChild(1)->setMetadata(22);
    //root.printElementsBelow();
    root.getChild(0)->getChild(1)->printElementsUp();
}

//int main() {
//    Node n1 = new Node();
//    n1.addNewChild();
//    n1.getChild(0)->setMetadata(1);
//    n1.addNewChild();
//    n1.getChild(1)->setMetadata(3);
//    n1.getChild(0)->addNewChild();
//    n1.getChild(0)->getChild(0)->setMetadata(2);
//    n1.printElementsBelow();
//    treeTest();
//}
