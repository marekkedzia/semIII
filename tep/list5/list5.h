#include <iostream>

#ifndef LIST5_LIST5_H
#define LIST5_LIST5_H

//1,2
class CRefCounter {
public:
    CRefCounter() { i_count; }

    int iAdd() { return ++i_count; };

    int iDec() { return --i_count; };

    int iGet() { return i_count; };

private:
    int i_count;
};

template<typename T>
class CMySmartPointer {
public:
    CMySmartPointer(T *pcPointer) {
        pc_pointer = pcPointer;
        pc_counter = new CRefCounter();
        pc_counter->iAdd();
    }

    CMySmartPointer(const CMySmartPointer &pcOther) {
        pc_pointer = pcOther.pc_pointer;
        pc_counter = pcOther.pc_counter;
        pc_counter->iAdd();
    }

    ~CMySmartPointer() {
        if (pc_counter->iDec() == 0)
            delete pc_pointer, pc_counter;
    }

    T &operator*();

    T *operator->();

    void operator=(const CMySmartPointer<T> &pcOther);

private:
    CRefCounter *pc_counter;
    T *pc_pointer;
};

template<typename T>
T &CMySmartPointer<T>::operator*() {
    return (*pc_pointer);
}

template<typename T>
T *CMySmartPointer<T>::operator->() {
    return (pc_pointer);
}

template<typename T>
void CMySmartPointer<T>::operator=(const CMySmartPointer<T> &pcOther) {
    if (pc_pointer != NULL && pc_counter->iDec() == 0)
        delete pc_pointer, pc_counter;

    pc_pointer = pcOther.pc_pointer;
    pc_counter = pcOther.pc_counter;
    pc_counter->iAdd();
}

//4
const int TAB_SIZE = 12;

class CTab {
private:
    void v_copy(const CTab &cOther);

    int *pi_tab;
    int i_size;
public:
    CTab() {
        pi_tab = new int[TAB_SIZE];
        i_size = TAB_SIZE;
    }

    CTab(const CTab &cOther);

    CTab(CTab &&cOther);

    CTab operator=(const CTab &cOther);

    CTab operator=(CTab &&cOther);

    ~CTab();

    bool bSetSize(int iNewSize);

    int iGetSize();
};

const std::string DEFAULT_TABLE_NAME = "DEFAULT";
const int DEFAULT_TABLE_SIZE = 5;
const std::string PARAMETER_FREE = "parameter-free";
const std::string CREATE_OBJECT_ERROR = "Cannot create object";
const std::string INCORRECT_SIZE_MESSAGE = "Field size must be a positive integer";
const std::string PARAMETER = "parameter";
const std::string COPY_SUFFIX = "_copy";
const std::string COPY = "Copy";
const std::string CHANGE_SIZE_ERROR = "Cannot change size";
const std::string NAME = "Name: ";
const std::string SIZE = ", Size:";
#endif //LIST5_LIST5_H
