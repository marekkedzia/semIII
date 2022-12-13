//
// Created by marek on 09.12.2022.
//
template<typename T>

class NodeDynamic {
public:
    NodeDynamic() {
        parentNode = NULL;
    };

    ~NodeDynamic() {
        for (int i = 0; i < iGetChildrenNumber(); i++) {
            delete children.at(i);
        }
        children.clear();
    }

    void vSetValue(T iNewVal);

    int iGetChildrenNumber();

    void vAddNewChild();

    bool bRemoveChild(NodeDynamic *pcChildNode);

    bool bIsRoot();

    NodeDynamic *pcGetParent();

    NodeDynamic *pcGetChild(int index);

    void vPrint();

    void vPrintAllBelow();

    bool bClearNode(NodeDynamic<T> *pcChildNode, int index);

private:
    std::vector<NodeDynamic<T> *> children;
    NodeDynamic<T> *parentNode;
    T content;
};

template<typename T>
void NodeDynamic<T>::vSetValue(T iNewVal) {
    content = iNewVal;
}

template<typename T>
int NodeDynamic<T>::iGetChildrenNumber() {
    return children.size();
}

template<typename T>
void NodeDynamic<T>::vAddNewChild() {
    NodeDynamic<T> *child = new NodeDynamic<T>();
    child->parentNode = this;
    children.push_back(child);
}

template<typename T>
bool NodeDynamic<T>::bClearNode(NodeDynamic<T> *pcChildNode, int index) {
    pcChildNode->parentNode = NULL;
    children.erase(index);
    return true;
}

template<typename T>
bool NodeDynamic<T>::bRemoveChild(NodeDynamic<T> *pcChildNode) {
    for (int i = 0; i < iGetChildrenNumber(); i++)
        if (children.at(i) == pcChildNode)
            return bClearNode(pcChildNode, i);

    return false;
}

template<typename T>
bool NodeDynamic<T>::bIsRoot() {
    return (parentNode == NULL);
}

template<typename T>
NodeDynamic<T> *NodeDynamic<T>::pcGetParent() {
    return parentNode;
}

template<typename T>
NodeDynamic<T> *NodeDynamic<T>::pcGetChild(int index) {
    if (index < 0 || index >= iGetChildrenNumber()) {
        std::cout << "Index is invalid" << std::endl;
        return NULL;
    }

    return children.at(index);
}

template<typename T>
void NodeDynamic<T>::vPrint() {
    std::cout << " " << content;
}

template<typename T>
void NodeDynamic<T>::vPrintAllBelow() {
    for (int i = 0; i < iGetChildrenNumber(); i++){
        children.at(i).vPrint();
        children.at(i).vPrintAllBelow();
    }
}

template<typename T>
class CTreeDynamic {
public:
    CTreeDynamic() {
        pc_root = new NodeDynamic<T>();
    }

    ~CTreeDynamic() {
        delete pc_root;
    }

    NodeDynamic<T> *pcGetRoot();

    void vPrintTree();

    bool bMoveSubtree(NodeDynamic<T> *pcParentNode, NodeDynamic<T> *pcNewChildNode);

private:
    NodeDynamic<T> *pc_root;
};

template<typename T>
NodeDynamic<T> *CTreeDynamic<T>::pcGetRoot() {
    return pc_root;
}

template<typename T>
void CTreeDynamic<T>::vPrintTree() {
    pc_root->vPrint();
    pc_root->vPrintAllBelow();
}

template<typename T>
bool CTreeDynamic<T>::bMoveSubtree(NodeDynamic<T> *pcParentNode, NodeDynamic<T> *pcNewChildNode) {
    pcParentNode->vAddNewChild(pcNewChildNode);
    pcNewChildNode->pcGetParent()->bRemoveChild(pcNewChildNode);
    return true;
}