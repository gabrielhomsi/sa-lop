#ifndef UNTITLED_SIMULATEDANNEALING_H
#define UNTITLED_SIMULATEDANNEALING_H

#include <vector>

class SimulatedAnnealing {
public:
    std::vector<std::vector<int> > C;
    int T;
    double decay_factor;
    int iterations;

    SimulatedAnnealing(std::vector<std::vector<int> > &C, int T, double decay_factor, int iterations);

    int run();
};


#endif //UNTITLED_SIMULATEDANNEALING_H
