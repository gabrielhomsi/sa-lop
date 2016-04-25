#ifndef SIMULATEDANNEALING_H
#define SIMULATEDANNEALING_H

#include <vector>
#include <utility>
#include "Solution.h"

class SimulatedAnnealing {
public:
    std::vector<std::vector<int>> C;
    double T;
    double decay_factor;
    int iterations;

    SimulatedAnnealing(std::vector<std::vector<int>> &C, double T, double decay_factor, int iterations);

    Solution run(Solution w);
};


#endif
