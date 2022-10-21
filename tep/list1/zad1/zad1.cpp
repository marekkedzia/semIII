#include "zad1.h"
#include "utils.h"

using std::cout;
using std::endl;

void allocateAndFillTable(int size) {
    if (!isCorrectSize(size))
        return;

    int *default_table_pointer;
    default_table_pointer = new int[size];

    for (int i = 0; i < size; i++)
        default_table_pointer[i] = DEFAULT_TABLE_VALUE;

    for (int i = 0; i < size; i++)
        cout << i << SPLIT_SIGN << default_table_pointer[i] << endl;

    delete[] default_table_pointer;
}

//int main() {
//    allocateAndFillTable(0);
//    allocateAndFillTable(-53);
//    allocateAndFillTable(5);
//}