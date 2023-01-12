#include "Individual.h"
#include "../utils.h"
#include "../problems/CapacityProblem.h"
#include <iostream>

using namespace std;
int GENE_EXIST = 1;

Individual::Individual(int genotypeSize) {
    genotypeLength = genotypeSize;
    genotypeChain = provideGenotype(genotypeLength);
    qualityRate = 0;
}

int Individual::provideGene() {
    return generateRandomBool() ? 1 : 0;
}

std::vector<int> Individual::provideGenotype(int genotypeLength) {
    vector<int> genotype;
    for (int i = 0; i < genotypeLength; i++)
        genotype.push_back(provideGene());

    return genotype;
}

void Individual::print() {
    for (int i = 0; i < genotypeLength; i++) {
        std::cout << genotypeChain.at(i) << " ";
    }

    std::cout << "qualityRate:" << qualityRate << endl;
}

void Individual::calculateQualityRate(CapacityProblem problemCredentials) {
    vector<double> values = problemCredentials.getValues();
    vector<double> weights = problemCredentials.getWeights();
    double value = 0;
    double weight = 0;

    for (int i = 0; i < genotypeLength; i++) {
        if (genotypeChain.at(i) == GENE_EXIST) {
            value += values.at(i);
            weight += weights.at(i);
        }
    }
    weight > problemCredentials.getCapacity() ? qualityRate = 0 : qualityRate = value;
}

double Individual::getQualityRate() { return qualityRate; }

double Individual::getGenotypeLength() { return genotypeLength; }

void Individual::setGene(int gene, int position) { genotypeChain.at(position) = gene; }

int Individual::getGene(int position) { return genotypeChain.at(position); }

Individual::~Individual() {
    genotypeChain.clear();
}

void Individual::mutate() {
    for (int i = 0; i < genotypeLength; i++) {
        if (genotypeChain.at(i) == 1)
            genotypeChain.at(i) = 0;
        else
            genotypeChain.at(i) = 1;
    }
};
