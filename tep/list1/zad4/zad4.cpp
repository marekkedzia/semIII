#include "zad4.h"
#include <iostream>
#include "utils.h"

using std::cout;
using std::string;

class Table {
private:
    string name;
    int *table;
    int size;

public:
    Table() {
        name = DEFAULT_TABLE_NAME;
        size = DEFAULT_TABLE_SIZE;
        table = new int[size];
        printActionLog(PARAMETER_FREE, name);
    };

    Table(string userTableName, int userTableSize) {
        if (!isCorrectSize(userTableSize)) {
            printActionLog(CREATE_OBJECT_ERROR, INCORRECT_SIZE_MESSAGE);
            return;
        }

        size = userTableSize;
        name = userTableName;
        table = new int[size];
        printActionLog(PARAMETER, name);
    }

    Table(Table &tableToCopy) {
        size = tableToCopy.size;
        name = tableToCopy.name + COPY_SUFFIX;
        table = tableToCopy.table;
        printActionLog(COPY, name);
    }

    ~Table() {
        delete[] table;
        printActionLog(DELETE, name);
    }

    void setName(string userTableName) {
        name = userTableName;
    }

    bool setSize(int userTableSize) {
        if (!isCorrectSize(userTableSize)) {
            printActionLog(CHANGE_SIZE_ERROR, INCORRECT_SIZE_MESSAGE);
            return false;
        }
        size = userTableSize;
        table = new int[userTableSize];
        return true;
    }

    Table *clone() {
        return new Table(name, size);
    }
};

void modTab(Table *tableToModify, int size) {
    tableToModify->setSize(size);
}

void modTab(Table tableToModify, int size) { //works
    tableToModify.setSize(size);
}

//int main() {
//    Table *table1 = new Table();
//    Table *table2 = new Table("name2", 4);
//    Table *table3 = new Table("name3", 5);
//    Table *table4 = new Table("name3", -5);
//       Table *table = new Table("name3", 6);
//    modTab(table, 1);
//    cout << table->size<<std::endl;
//    modTab(*table, 1);
//    cout << table->size;
//}
