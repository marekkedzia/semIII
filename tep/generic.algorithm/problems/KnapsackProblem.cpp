//
// Created by marek on 07.01.2023.
//
#include "KnapsackProblem.h"
#include <iostream>
#include <string>

KnapsackProblem::KnapsackProblem(const std::string &filePath) {
    ifstream file(filePath);

    if (!file.is_open())
        throw std::invalid_argument("Cannot open the file, path is invalid");


    double capacity;
    vector<double> providedWeights;
    vector<double> providedValues;

    string word;
    int i = 0;

    while (file >> word) {
        if (i == 1)
            capacity = stod(word);
        if (i == 3)
            providedWeights = convertToVector(word);
        if (i == 5)
            providedValues = convertToVector(word);
        i++;
    }
    file.close();

    if (capacity < 0)
        throw std::invalid_argument("Capacity must be positive number");

    if (providedWeights.size() != providedValues.size())
        throw std::invalid_argument("Values and weights have to be the same size");

    setCapacity(capacity);
    setWeights(providedWeights);
    setValues(providedValues);
}

void KnapsackProblem::printItems() {
    cout << "Max capacity: " << getCapacity() << " Items: " << getWeights().size() << endl;
    for (int i = 0; i < getWeights().size(); i++) {
        cout << i + 1 << ". weight: " << getWeights().at(i) << " value: " << getValues().at(i) << endl;
    }
}