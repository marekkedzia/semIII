#include "utils.h"
#include <iostream>
bool isCorrectSize(int size) {
    return size >= 0;
}

void printActionLog(std::string actionName, std::string value) {
    std::cout << actionName << MESSAGE_SPLIT_SIGN << value << std::endl;
}