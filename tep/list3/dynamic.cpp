#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::endl;

class CNodeDynamic {
private:
    vector<CNodeDynamic *> children;
    CNodeDynamic *parent;
    int metadata;

public:
    CNodeDynamic() {
        metadata = 0;
        parent = NULL;
    };

    ~CNodeDynamic() {
        if (parent != NULL)
            delete parent;
        while (!children.empty()) {
            children.pop_back();
        }
    };

    void vSetValue(int iNewVal) {
        metadata = iNewVal;
    };

    int iGetChildrenNumber() {
        return children.size();
    };

    void vAddNewChild() {
        CNodeDynamic *newNode;
        newNode = new CNodeDynamic();
        newNode->parent = this;
        children.push_back(newNode);
    };

    CNodeDynamic *pcGetChild(int index) {
        if (index < 0 || index >= children.size()) {
            cout << "Index is incorrect" << endl;
            return NULL;
        }

        return children.at(index);
    };

    void vPrint() {
        cout << " " << metadata;
    };

    void vPrintAllBelow() {
        vPrint();
        if (!children.empty())
            for (int i = 0; i < children.size(); i++)
                children.at(i)->vPrintAllBelow();
    };

    void setChild(int index, CNodeDynamic *child) {
        children.at(index) = child;
    }

    void setParent(CNodeDynamic *parent) {
        parent = parent;
    }

    void deleteBoundary(CNodeDynamic *boundedChild) {
        for (int i = 0; i < parent->children.size(); i++) {
            if (parent->children.at(i) == boundedChild) {
                parent->children.erase(parent->children.begin() + i);
            }
        }
    }
};

class CTreeDynamic {
private:
    CNodeDynamic *root;
public:
    CTreeDynamic() {
        root = new CNodeDynamic();
    };

    ~CTreeDynamic() {
        delete root;
    };

    CNodeDynamic *pcGetRoot() {
        return (root);
    }

    void vPrintTree() {
        root->vPrintAllBelow();
    };

    bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode) {
        pcParentNode->vAddNewChild();
        pcParentNode->setChild(pcParentNode->iGetChildrenNumber() - 1, pcNewChildNode);
        pcNewChildNode->deleteBoundary(pcNewChildNode);
        pcNewChildNode->setParent(pcParentNode);
    };
};

//int main() {
////    CNodeDynamic *n1 = new CNodeDynamic();
////    n1->vAddNewChild();
////    n1->pcGetChild(0)->vSetValue(1);
////    n1->vAddNewChild();
////    n1->pcGetChild(1)->vSetValue(3);
////    n1->pcGetChild(0)->vAddNewChild();
////    n1->pcGetChild(0)->pcGetChild(0)->vSetValue(2);
////    n1->vPrintAllBelow();
//
//    CTreeDynamic *n2 = new CTreeDynamic();
//    n2->pcGetRoot()->vAddNewChild();
//    n2->pcGetRoot()->vAddNewChild();
//    n2->pcGetRoot()->vAddNewChild();
//    n2->pcGetRoot()->pcGetChild(0)->vSetValue(1);
//    n2->pcGetRoot()->pcGetChild(1)->vSetValue(2);
//    n2->pcGetRoot()->pcGetChild(2)->vSetValue(3);
//    n2->pcGetRoot()->pcGetChild(2)->vAddNewChild();
//    n2->pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);
//    n2->pcGetRoot()->vSetValue(0);
//    n2->pcGetRoot()->vPrintAllBelow();
//    cout<< endl;
//
//    CTreeDynamic *n3 = new CTreeDynamic();
//    n3->pcGetRoot()->vAddNewChild();
//    n3->pcGetRoot()->vAddNewChild();
//    n3->pcGetRoot()->vSetValue(50);
//    n3->pcGetRoot()->pcGetChild(0)->vSetValue(54);
//    n3->pcGetRoot()->pcGetChild(1)->vSetValue(55);
//    n3->pcGetRoot()->pcGetChild(0)->vAddNewChild();
//    n3->pcGetRoot()->pcGetChild(0)->vAddNewChild();
//    n3->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
//    n3->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);
//    n3->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
//    n3->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);
//    n3->pcGetRoot()->vPrintAllBelow();
//    cout<< endl;
//
//    n2->bMoveSubtree(n2->pcGetRoot()->pcGetChild(2), n3->pcGetRoot()->pcGetChild(0));
//    n2->vPrintTree();
//    cout<< endl;
//
//    n3->vPrintTree();
//}


