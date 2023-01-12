//
// Created by marek on 06.01.2023.
//

#ifndef GENERIC_ALGORITHM_INDIVIDUAL_H
#define GENERIC_ALGORITHM_INDIVIDUAL_H

#include <vector>
#include "../problems/CapacityProblem.h"

class Individual {
    std::vector<int> genotypeChain;
    int genotypeLength;
    double qualityRate;
public:
    Individual(int genotypeLength);

    ~Individual();

    void print();

    void calculateQualityRate(CapacityProblem capacityProblem);

    double getQualityRate();

    double getGenotypeLength();

    void setGene(int gene, int position);

    int getGene(int position);

    void mutate();

private:
    static std::vector<int> provideGenotype(int genotypeLength);

    static int provideGene();
};


#endif //GENERIC_ALGORITHM_INDIVIDUAL_H
