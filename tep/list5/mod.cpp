//#include <iostream>
//#include "list5.h"
//
//using std::cout;
//using std::string;
//
////4
//void CTab::v_copy(const CTab &cOther) {
//    pi_tab = new int[cOther.i_size];
//    for (int i = 0; i < cOther.i_size; i++)
//        pi_tab[i] = cOther.pi_tab[i];
//    i_size = cOther.i_size;
//}
//
//CTab::CTab(const CTab &cOther) {
//    v_copy(cOther);
//}
//
//CTab::CTab(CTab &&cOther) {
//    pi_tab = cOther.pi_tab;
//    i_size = cOther.i_size;
//    cOther.pi_tab = NULL;
//}
//
//CTab CTab::operator=(const CTab &cOther) {
//    if (pi_tab != NULL)
//        delete pi_tab;
//    v_copy(cOther);
//    return *this;
//}
//
//CTab CTab::operator=(CTab &&cOther) {
//    if (pi_tab != NULL)
//        delete pi_tab;
//    pi_tab = cOther.pi_tab;
//    i_size = cOther.i_size;
//    cOther.pi_tab = NULL;
//    return *this;
//}
//
//CTab::~CTab() {
//    if (pi_tab != NULL)
//        delete pi_tab;
//}
//
//bool CTab::bSetSize(int iNewSize) {
//    if (iNewSize < 0) {
//        std::cout << "New size must be a positive integer" << std::endl;
//        return false;
//    }
//    int *newTab = new int[iNewSize];
//    iNewSize = std::min(i_size, iNewSize);
//
//    for (int i = 0; i < iNewSize; i++)
//        newTab[i] = pi_tab[i];
//
//    i_size = iNewSize;
//    pi_tab = newTab;
//    return true;
//}
//
//int CTab::iGetSize() {
//    return i_size;
//}
//
//class Table {
//private:
//    string name;
//    int *table;
//    int size;
//
//public:
//    Table() {
//        name = DEFAULT_TABLE_NAME;
//        size = DEFAULT_TABLE_SIZE;
//        table = new int[size];
//        printActionLog(PARAMETER_FREE, name);
//    };
//
//    bool isCorrectSize(int value) {
//        return value >= 0;
//    }
//
//    Table(string userTableName, int userTableSize) {
//        if (!isCorrectSize(userTableSize)) {
//            printActionLog(CREATE_OBJECT_ERROR, INCORRECT_SIZE_MESSAGE);
//            return;
//        }
//
//        size = userTableSize;
//        name = userTableName;
//        table = new int[size];
//        printActionLog(PARAMETER, name);
//    }
//
//    Table(Table &&tableToCopy) {
//        size = tableToCopy.size;
//        name = tableToCopy.name + COPY_SUFFIX;
//        table = tableToCopy.table;
//        printActionLog(COPY, name);
//    }
//
//    void setName(string userTableName) {
//        name = userTableName;
//    }
//
//    void printActionLog(std::string action, std::string message) {
//        std::cout << action << ":" << message << std::endl;
//    }
//
//    bool setSize(int userTableSize) {
//        if (!isCorrectSize(userTableSize)) {
//            printActionLog(CHANGE_SIZE_ERROR, INCORRECT_SIZE_MESSAGE);
//            return false;
//        }
//        size = userTableSize;
//        table = new int[userTableSize];
//        return true;
//    }
//
//    Table *clone() {
//        return new Table(name, size);
//    }
//
//    void operator=(Table &&other) {
//        if (table != NULL)
//            delete table;
//
//        table = other.table;
//        size = other.size;
//        name = other.name;
//        other.table = NULL;
//    }
//
//    Table operator+(Table &&other) {
//        int newLength = size + other.size;
//        int *newArray = new int[newLength];
//        int pointer = 0;
//
//        for (int i = 0; i < size; i++) {
//            newArray[pointer] = table[i];
//            pointer += 1;
//        }
//        for (int i = 0; i < other.size; i++) {
//            newArray[pointer] = other.table[i];
//            pointer += 1;
//        }
//
//        Table newCTable(name + " + " + other.name, newLength);
//        newCTable.table = newArray;
//
//        return newCTable;
//    }
//
//    void print() {
//        std::cout << NAME << name << SIZE << size << std::endl;
//        for (int i = 0; i < size; i++)
//            std::cout << i << ". " << table[i] << std::endl;
//    }
//
//    void setValue(int index, int value) {
//        table[index] = value;
//    }
//
//    int getValue(int index) {
//        return table[index];
//    }
//};
//
//int main() {
//    int copies = 0;
//    int *pointer = new int[123];
//    CMySmartPointer<int> p1(pointer);
//    copies++;
//    p1.operator->()[0] = 123;
//    p1.operator->()[1] = 456;
//    p1.operator->()[2] = 789;
//    p1.operator->()[3] = 012;
//    CMySmartPointer<int> p2(p1);
//    copies++;
//    CMySmartPointer<int> p3(new int[7]);
//    copies++;
//    p3 = p2;
//    std::cout << p2.operator->()[0] << std::endl;
//    std::cout << p2.operator->()[1] << std::endl;
//    std::cout << p2.operator->()[2] << std::endl;
//    std::cout << p2.operator->()[3] << std::endl;
//    std::cout << std::endl;
//    std::cout << p3.operator->()[0] << std::endl;
//    std::cout << p3.operator->()[1] << std::endl;
//    std::cout << p3.operator->()[2] << std::endl;
//    std::cout << p3.operator->()[3] << std::endl;
//    std::cout << std::endl;
//    CTab ctab1, ctab2;
//    ctab1.bSetSize(5);
//    ctab2.bSetSize(7);
//    ctab1 = std::move(ctab2);
//    std::cout << std::endl;
//    std::cout << ctab1.iGetSize() << std::endl;
//    std::cout << std::endl;
//    Table tab1("a", 1);
//    tab1.setValue(0, 123);
//    Table tab2("b", 2);
//    copies++;
//    tab2.setValue(0, 456);
//    tab2.setValue(1, 789);
//    Table tab3;
//    tab2 + std::move(tab3);
//    tab3.print();
//    copies++;
//    std::cout << "Liczba utworzonych kopi: " << copies;
//}
