#ifndef SUMMARY_H
#define SUMMARY_H


#include "Graph.h"
#include "Solution.h"

class Summary {
public:
    Graph g;

    Summary(Graph &g);

    void show(Solution initial_w, Solution best_w);
};


#endif