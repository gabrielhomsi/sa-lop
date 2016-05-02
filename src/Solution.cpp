#include "Solution.h"
#include "Random.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

Solution Solution::initial(Graph &g) {
    std::vector<int> pi;

    for (unsigned int i = 0; i < g.edges.size(); i++) {
        pi.push_back(i);
    }

    return Solution(pi, g);
}

Solution::Solution(std::vector<int> pi, Graph &g) {
    this->pi = pi;
    this->cost = evaluate(g);
}

Solution::Solution(std::vector<int> pi, int cost) {
    this->pi = pi;
    this->cost = cost;
}

int Solution::evaluate(Graph &g) {
    int cost = 0;

    for (unsigned int i = 0; i < g.edges.size(); i++) {
        for (unsigned int j = i + 1; j < g.edges.size(); j++) {
            cost += g.edges[pi[i]][pi[j]];
        }
    }

    return cost;
}