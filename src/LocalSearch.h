#ifndef LOCALSEARCH_H
#define LOCALSEARCH_H


#include "Solution.h"
#include "Parameters.h"

class LocalSearch {
public:
    Graph g;

    int move_strategy;

    Parameters parameters;

    LocalSearch(Graph g, int move_strategy);

    Solution run(Solution s_init);

    void searchNeighborhood(Solution &s);

    void firstAdmissibleMoveStrategy(Solution &s);

    void bestMoveStrategy(Solution &s);
};


#endif
