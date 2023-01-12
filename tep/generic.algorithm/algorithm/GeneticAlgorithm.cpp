#include "GeneticAlgorithm.h"
#include <iostream>

using namespace std;

GeneticAlgorithm::GeneticAlgorithm(int population, double crossProb, double mutationProb, int executions) {
    populationSize = population;
    crossProbabilityPercentage = crossProb;
    mutationProbabilityPercentage = mutationProb;
    remainingExecutions = executions;
}

GeneticAlgorithm::~GeneticAlgorithm() {
    individuals.clear();
}

void GeneticAlgorithm::providePopulation(int genotypeLength, const CapacityProblem &capacityProblem) {
    for (int i = 0; i < populationSize; i++) {
        individuals.push_back(new Individual(genotypeLength));
        individuals.at(i)->calculateQualityRate(capacityProblem);
    }
}

void GeneticAlgorithm::printPopulation() {
    for (int i = 0; i < populationSize; i++) {
        std::cout << "Gene " << i + 1 << ". ";
        individuals.at(i)->print();
    }
}

void GeneticAlgorithm::calculateQualityRate(const CapacityProblem &capacityProblem) {
    for (int i = 0; i < populationSize; i++)
        individuals.at(i)->calculateQualityRate(capacityProblem);
}

Individual *GeneticAlgorithm::findParent() {
    Individual *candidate1 = individuals.at(generateInt(0, individuals.size() - 1));
    Individual *candidate2 = individuals.at(generateInt(0, individuals.size() - 1));
    return candidate1->getQualityRate() > candidate2->getQualityRate() ? candidate1 : candidate2;
}

Individual *GeneticAlgorithm::mergeParents(int cutSpot, Individual parent1, Individual parent2) {
    Individual *child = new Individual(parent1.getGenotypeLength());
    for (int i = 0; i < child->getGenotypeLength(); i++) {
        if (i < cutSpot)
            child->setGene(parent1.getGene(i), i);
        else
            child->setGene(parent2.getGene(i), i);
    }
    //child->print();
    return child;
}

void GeneticAlgorithm::crossPopulation() {
    vector<Individual *> nextGeneration;
    while (nextGeneration.size() != individuals.size()) {
        Individual *parent1 = findParent();
        Individual *parent2 = findParent();

        if (crossProbabilityPercentage > generateInt(0, 100)) {
            nextGeneration.push_back(
                    mergeParents(generateInt(0, parent1->getGenotypeLength()), *parent1, *parent2));
            nextGeneration.push_back(
                    mergeParents(generateInt(0, parent1->getGenotypeLength()), *parent2, *parent1));
        } else {
            nextGeneration.push_back(parent1);
            nextGeneration.push_back(parent2);
        }
    }
    individuals = nextGeneration;
}

void GeneticAlgorithm::solve(int genotypeLength, const CapacityProblem &capacityProblem) {
    cout << "POPULATION" << endl;
    providePopulation(genotypeLength, capacityProblem);
    printPopulation();
    Individual bestGene(genotypeLength);

    while (remainingExecutions > 0) {
        crossPopulation();
        bestGene.calculateQualityRate(capacityProblem);
        for (int i = 0; i < individuals.size(); i++) {
            Individual* mutatedGene = mutate(i);
            mutatedGene->calculateQualityRate(capacityProblem);
            if(mutatedGene->getQualityRate()>bestGene.getQualityRate())
                bestGene = *mutatedGene;
        }
        remainingExecutions--;
    }
    cout << "RESULTS" << endl;
    printPopulation();
    cout << "BEST GENE" << endl;
    bestGene.print();
}

Individual* GeneticAlgorithm::mutate(int position) {
    if (mutationProbabilityPercentage > generateInt(0, 100)) {
        individuals.at(position)->mutate();
    }
    return individuals.at(position);
}
