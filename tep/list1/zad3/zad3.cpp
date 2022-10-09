#include "zad3.h"
#include <iostream>
#include "utils.h"

using std::cout;
using std::endl;

bool b_dealloc_table_2_dim(int **tablePointer, int sizeX, int sizeY) { //redundant parameter sizeY
    if (!isCorrectSize(sizeX) || !isCorrectSize(sizeY))
        return false;

    tablePointer = new int *[sizeX];
    for (int i = 0; i < sizeX; i++)
        delete tablePointer[i];

    return true;
}

//int main() {
//    int **pointer;
//    cout << b_dealloc_table_2_dim(pointer, 5, 3) << endl;
//    int **pointer2;
//    cout << b_dealloc_table_2_dim(pointer2, -5, 3) << endl;
//    int **pointer3;
//    cout << b_dealloc_table_2_dim(pointer3, 5, -3) << endl;
//    int **pointer4;
//    cout << b_dealloc_table_2_dim(pointer4, -5, -3) << endl;
//};