#include <iostream>
#include "main.h"
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

    bool isCorrectSize(int size) {
        return size >= 0;
    }

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

    void setName(string userTableName) {
        name = userTableName;
    }

    void printActionLog(std::string action, std::string message) {
        std::cout << action << ":" << message << std::endl;
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

    void operator=(const Table &other) {
        table = other.table;
        size = other.size;
    }

    Table operator+(Table &other) {
        Table *tempTable = new Table(CONCATED, size + other.size);
        for (int i = 0; i < size; i++)
            tempTable->setValue(i, table[i]);

        for (int i = size; i < size + other.size; ++i)
            tempTable->setValue(i, other.getValue(i - size));

        return *tempTable;
    }

    void printT() {
        std::cout << NAME << name << SIZE << size << std::endl;
        for (int i = 0; i < size; i++)
            std::cout << i << ". " << table[i] << std::endl;
    }

    void setValue(int index, int value) {
        table[index] = value;
    }

    int getValue(int index) {
        return table[index];
    }
};

int main() {
    //zad1
    Table table1, table2;
    table1.setSize(8);
    table2.setSize(5);
    table1 = table2;
    table1.printT();
    table2.printT();
    //zad3
    table1.setValue(0, 1);
    table1.setValue(1, 2);
    table1.setValue(2, 3);
    table1.setValue(3, 4);
    table1.setValue(4, 5);
    table2.setValue(0, 51);
    table2.setValue(1, 52);
    table2.setValue(2, 53);
    table2.setValue(3, 54);
    table2.setValue(4, 55);
    table1 = table2;
    table2.setValue(2, 123);
    table1.printT();
    table2.printT();
    //zad4
    Table table5;
    Table table3, table4;
    table3.setSize(6);
    table4.setSize(4);
    table3.setValue(0, 1);
    table3.setValue(1, 2);
    table3.setValue(2, 3);
    table3.setValue(3, 4);
    table3.setValue(4, 5);
    table3.setValue(5, 6);
    table3.setValue(6, 7);

    table4.setValue(0, 51);
    table4.setValue(1, 52);
    table4.setValue(2, 53);
    table4.setValue(3, 54);
    table4.setValue(4, 55);
    table5 = table3 + table4;
    table5.printT();
    return 0;
}


