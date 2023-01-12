//
// Created by marek on 06.01.2023.
//
#include "CapacityProblem.h"
#include <stdexcept>

CapacityProblem::~CapacityProblem() {
    weights.clear();
    values.clear();
}

CapacityProblem::CapacityProblem(double capacity, const vector<double> &itemsWeights,
                                 const vector<double> &itemsValues) {
    if (itemsValues.size() != itemsWeights.size())
        throw std::invalid_argument("Values and weights have to be the same size");

    if (capacity < 0)
        throw std::invalid_argument("Capacity must be positive number");

    maxCapacity = capacity;
    weights = itemsWeights;
    values = itemsValues;
}

double CapacityProblem::getCapacity() { return maxCapacity; }

std::vector<double> CapacityProblem::getWeights() { return weights; }

std::vector<double> CapacityProblem::getValues() { return values; }

void CapacityProblem::setCapacity(int capacity) { maxCapacity = capacity; }

void CapacityProblem::setWeights(std::vector<double> weights) { this->weights = weights; }

void CapacityProblem::setValues(std::vector<double> values) { this->values = values; }

CapacityProblem::CapacityProblem() {}
