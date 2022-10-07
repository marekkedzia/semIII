//
// Created by marek on 06.10.2022.
//

#include "zad1.h"

using std::cout;
using std::endl;

void setValue(int *pointer, int value) {
    *pointer = value;
}

bool isCorrectSize(int size) {
    return size >= 0;
}

void v_alloc_table_fill_34(int size) {
    if (!isCorrectSize(size))
        return;

    int *default_table;
    default_table = new int[size];

    for (int i = 0; i < size; i++)
        setValue(&default_table[i], DEFAULT_TABLE_FILLER);

    for (int i = 0; i < size; i++)

        cout << i << SPLIT_SIGN << default_table[i] << endl;

    delete default_table;
}

int main() {
    v_alloc_table_fill_34(0);
    v_alloc_table_fill_34(-53);
    v_alloc_table_fill_34(5);
}