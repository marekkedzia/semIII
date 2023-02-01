#ifndef GENERIC_ALGORITHM_GENETICALGORITHM_H
#define GENERIC_ALGORITHM_GENETICALGORITHM_H

#include <vector>
#include <random>
#include "Individual.h"
#include "../utils.h"

using namespace std;

class GeneticAlgorithm {
private:
    std::vector<Individual *> individuals;
    int populationSize;
    double crossProbabilityPercentage;
    double mutationProbabilityPercentage;
    int remainingExecutions;

    Individual* findParent();

    void calculatePopulationQualityRate(const CapacityProblem &capacityProblem);

    Individual * mergeParents(int cutSpot, Individual parent1, Individual parent2);

public:
    GeneticAlgorithm(int population, double crossProb, double mutationProb, int executions);

    ~GeneticAlgorithm();

    void printPopulation();

    void solve(int genotypeLength, const CapacityProblem &capacityProblem);

    void providePopulation(int genotypeLength, const CapacityProblem &capacityProblem);

    void crossPopulation();

    Individual * mutate(int position);
};

#endif //GENERIC_ALGORITHM_GENETICALGORITHM_H
