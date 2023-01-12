//
// Created by marek on 07.01.2023.
//

#ifndef GENERIC_ALGORITHM_KNAPSACKPROBLEM_H
#define GENERIC_ALGORITHM_KNAPSACKPROBLEM_H

#include "CapacityProblem.h"
#include <string>
#include "../utils.h"

using namespace std;

class KnapsackProblem : public CapacityProblem {
public:
    using CapacityProblem::CapacityProblem;

    KnapsackProblem(const string &filePath);

    void printItems();
};


#endif //GENERIC_ALGORITHM_KNAPSACKPROBLEM_H
