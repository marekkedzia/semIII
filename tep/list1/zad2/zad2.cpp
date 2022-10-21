#include <iostream>
#include "utils.h"
#include "zad1.h"

using std::cout;
using std::endl;

bool allocateTable(int ***tablePointer, int sizeX, int sizeY) {
    if (!isCorrectSize(sizeX) || !isCorrectSize(sizeY))
        return false;

    *tablePointer = new int *[sizeX];
    for (int i = 0; i < sizeX; i++)
        (*tablePointer)[i] = new int[sizeY];

    return true;
}

//int main() {
//    int **pointer;
//    cout << allocateTable(&pointer, 5, 3) << endl;
//    int **pointer2;
//    cout << allocateTable(&pointer2, -5, 3) << endl;
//    int **pointer3;
//    cout << allocateTable(&pointer3, 5, -3) << endl;
//    int **pointer4;
//    cout << allocateTable(&pointer4, -5, -3) << endl;
//};