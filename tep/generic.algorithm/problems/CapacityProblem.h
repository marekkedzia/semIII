//
// Created by marek on 06.01.2023.
//
using namespace std;

#include <vector>

#ifndef GENERIC_ALGORITHM_CAPACITYPROBLEM_H
#define GENERIC_ALGORITHM_CAPACITYPROBLEM_H


class CapacityProblem {
private:
    double maxCapacity;
    std::vector<double> weights;
    std::vector<double> values;
public:
    CapacityProblem(double capacity, const std::vector<double> &weights, const std::vector<double> &values);

    CapacityProblem();

    ~CapacityProblem();

    double getCapacity();

    std::vector<double> getWeights();

    std::vector<double> getValues();

    void setCapacity(int capacity);

    void setWeights(vector<double> weights);

    void setValues(vector<double> values);
};


#endif //GENERIC_ALGORITHM_CAPACITYPROBLEM_H
