#include <iostream>
#include "Graph.h"

void Graph::read() {
    unsigned int n;

    std::cin >> n;

    edges.resize(n + 1);

    for (unsigned int i = 1; i < edges.size(); i++) {
        edges[i].resize(edges.size());
    }

    for (unsigned int i = 1; i < edges.size(); i++) {
        for (unsigned int j = 1; j < edges[i].size(); j++) {
            std::cin >> edges[i][j];
        }
    }
}
