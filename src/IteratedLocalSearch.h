#ifndef ITERATEDLOCALSEARCH_H
#define ITERATEDLOCALSEARCH_H


#include "Solution.h"
#include "Parameters.h"

class IteratedLocalSearch {
public:
    Graph g;

    int iterations;

    int ls_move_strategy;

    Parameters parameters;

    IteratedLocalSearch(Graph g, int iterations, int ls_move_strategy);

    Solution run(Solution w);

    Solution perturbation(Solution s_star);

    bool acceptanceCriterion(Solution &s_star, Solution &s_star_prime);
};


#endif
