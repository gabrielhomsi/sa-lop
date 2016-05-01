#ifndef SUMMARY_H
#define SUMMARY_H

#include <chrono>
#include "Graph.h"
#include "Solution.h"

using namespace std::chrono;

class Summary {
public:
    Graph g;

    Parameters parameters;

    Summary(Graph &g);

    void show(Solution best_w, high_resolution_clock::time_point t1);
};


#endif