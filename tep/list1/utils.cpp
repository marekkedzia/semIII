#include "utils.h"
#include <iostream>

void setValue(int *pointer, int value) {
    *pointer = value;
}

bool isCorrectSize(int size) {
    return size >= 0;
}

void printActionLog(std::string actionName, std::string value) {
    std::cout << actionName << MESSAGE_SPLIT_SIGN << value << std::endl;
}