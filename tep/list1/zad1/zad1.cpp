//
// Created by marek on 06.10.2022.
//

#include "zad1.h"
#include "utils.h"

using std::cout;
using std::endl;

void v_alloc_table_fill_34(int size) {
    if (!isCorrectSize(size))
        return;

    int *default_table_pointer;
    default_table_pointer = new int[size];

    for (int i = 0; i < size; i++)
        setValue(&default_table_pointer[i], DEFAULT_TABLE_FILLER);

    for (int i = 0; i < size; i++)
        cout << i << SPLIT_SIGN << default_table_pointer[i] << endl;

    delete default_table_pointer;
}

//int main() {
//    v_alloc_table_fill_34(0);
//    v_alloc_table_fill_34(-53);
//    v_alloc_table_fill_34(5);
//}