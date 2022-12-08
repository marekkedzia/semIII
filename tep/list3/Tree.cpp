#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::endl;

class CNodeStatic {
public:
    vector<CNodeStatic> v_children;
    CNodeStatic *pc_parent;
    int i_val;

public:
    CNodeStatic() {
        i_val = 1;
        pc_parent = NULL;
    };

    ~CNodeStatic() {
        while (!v_children.empty())
            v_children.pop_back();
    };

    void vSetValue(int iVal) {
        i_val = iVal;
    };

    void vAddNewChild() {
        CNodeStatic newNode;
        newNode.pc_parent = this;
        v_children.push_back(newNode);
    };

    CNodeStatic *pcGetChild(int iIndex) {
        if (iIndex >= v_children.size() || iIndex < 0) {
            cout << "Index is incorrect" << endl;
            return NULL;
        }
        return &v_children.at(iIndex);
    };

    void vPrint() {
        cout << "->" << i_val;
    };

    void vPrintAllBelow() {
        vPrint();
        if (!v_children.empty())
            for (int i = 0; i < v_children.size(); i++)
                v_children.at(i).vPrintAllBelow();
    };
};

class CTreeStatic {
private:
    CNodeStatic c_root;
public:
    CTreeStatic() {
        c_root = CNodeStatic();
    };

    ~CTreeStatic() {
        delete &c_root;
    };

    CNodeStatic *pcGetRoot() {
        return &c_root;
    }

    void vPrintNodesBelow(CNodeStatic *node) {
        node->vPrintAllBelow();
    }

};

int main() {
    CTreeStatic *n2 = new CTreeStatic();
    n2->pcGetRoot()->vAddNewChild();
    n2->pcGetRoot()->vAddNewChild();
    n2->pcGetRoot()->vAddNewChild();
    n2->pcGetRoot()->pcGetChild(0)->vSetValue(1);
    n2->pcGetRoot()->pcGetChild(0)->vAddNewChild();
    n2->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(2);
    n2->pcGetRoot()->pcGetChild(0)->vAddNewChild();
    n2->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(3);
    n2->pcGetRoot()->pcGetChild(1)->vSetValue(4);
    n2->pcGetRoot()->pcGetChild(2)->vSetValue(5);
    n2->pcGetRoot()->pcGetChild(2)->vAddNewChild();
    n2->pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(6);
    n2->pcGetRoot()->vSetValue(0);
    n2->pcGetRoot()->vPrintAllBelow();
    cout << endl;
    n2->vPrintNodesBelow(n2->pcGetRoot()->pcGetChild(0));
    cout << endl;
}