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
        this->name = DEFAULT_TABLE_NAME;
        this->size = DEFAULT_TABLE_SIZE;
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

//    Table *clone() {
//        return new Table(*this);
//    }
    Table *clone() {
        return new Table(name, size);
    }
};

void modTab(Table *tableToModify, int size) {
    tableToModify->setSize(size);
}

void modTab(Table tableToModify, int size) {
    tableToModify.setSize(size);
}
