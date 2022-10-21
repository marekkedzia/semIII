#include <iostream>
#include "utils.h"
#include "zad2.h"

using std::cout;
using std::endl;

bool deallocateTable(int ***tablePointer, int sizeX, int sizeY) { //redundant parameter sizeY
    if (!isCorrectSize(sizeX) || !isCorrectSize(sizeY))
        return false;

    for (int i = 0; i < sizeX; i++)
        delete[] (*tablePointer)[i];

    delete[] *tablePointer;

    return true;
}

int main() {
    int sizeX = 5;
    int sizeY = 5;
    int **pointer;
    allocateTable(&pointer, sizeX, sizeY);
    cout << deallocateTable(&pointer, sizeX, sizeY) << endl;
    int **pointer2;
    cout << deallocateTable(&pointer2, -5, 3) << endl;
    int **pointer3;
    cout << deallocateTable(&pointer3, 5, -3) << endl;
    int **pointer4;
    cout << deallocateTable(&pointer4, -5, -3) << endl;
};