#include "algorithm/GeneticAlgorithm.h"
#include "./problems/KnapsackProblem.h"

int main() {
//    GeneticAlgorithm ga(1000, 98, 20, 100);
//     KnapsackProblem ka(10, {1, 0.6, 4, 2.7, 3.1}, {1, 2, 4, 6, 16});
//    ga.solve(5, ka);

    GeneticAlgorithm ga1(1000, 98, 20, 100);
    KnapsackProblem ka1("../problems.example/example1.txt");
    ka1.printItems();
    ga1.solve(4, ka1);
    return 0;
}
