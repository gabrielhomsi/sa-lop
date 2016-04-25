#include "SimulatedAnnealing.h"
#include "Solution.h"
#include "Random.h"
#include <cstdlib>
#include <cmath>
#include <iostream>

SimulatedAnnealing::SimulatedAnnealing(std::vector<std::vector<int>> &C, double T, double decay_factor,
                                       int iterations) {
    this->C = C;
    this->T = T;
    this->decay_factor = decay_factor;
    this->iterations = iterations;
}

Solution SimulatedAnnealing::run(Solution w) {
    double e = 2.718281828459045;

    for (double temperature = this->T; temperature > 1; temperature *= this->decay_factor) {
        for (int m = 0; m < this->iterations; m++) {
            Solution w_prime = w.neighbor(C);
            int delta = w_prime.cost - w.cost;

            if (delta >= 0 || util::random_double() <= pow(e, delta / temperature)) {
                w = w_prime;

//                std::cout << "w.cost = " << w.cost << ", temperature = " << temperature << std::endl;
            }
        }
    }

    if (w.cost != w.evaluate(C)) {
        std::cout << "ERROR! w.cost != w.evaluate(C)" << std::endl;
    }

    return w;
}