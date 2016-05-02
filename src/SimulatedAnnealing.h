#ifndef SIMULATEDANNEALING_H
#define SIMULATEDANNEALING_H


#include <vector>
#include <utility>
#include "Solution.h"
#include "Parameters.h"

class SimulatedAnnealing {
public:
    Graph g;

    double T;

    double decay_factor;

    int iterations;

    Parameters parameters;

    SimulatedAnnealing(Graph &g, double T, double decay_factor, int iterations);

    Solution run(Solution s_initial);
};


#endif
