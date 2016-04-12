#include "SimulatedAnnealing.h"
#include "Solution.h"
#include <cstdlib>
#include <cmath>

SimulatedAnnealing::SimulatedAnnealing(std::vector<std::vector<int> > &C, int T, double decay_factor, int iterations) {
    this->C = C;
    this->T = T;
    this->decay_factor = decay_factor;
    this->iterations = iterations;
}

int SimulatedAnnealing::run() {
    double e = 2.718281828459045;

    Solution w = Solution::initial(C);

    for (double temperature = this->T; temperature > 1; temperature *= this->decay_factor) {
        for (int m = 0; m < this->iterations; m++) {
            Solution w_prime = w.neighbor(C);
            int delta = w_prime.cost - w.cost;

            if (delta >= 0 || ((double) rand() / RAND_MAX) <= pow(e, delta / temperature)) {
                w = w_prime;
            }
        }
    }

    return w.cost;
}