#ifndef GRAPH_H
#define GRAPH_H


#include <vector>
#include "Parameters.h"

class Graph {

public:
    std::vector<std::vector<int>> edges;

    Parameters parameters;

    Graph();

    void read();
};


#endif
