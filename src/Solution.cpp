#include "Solution.h"
#include "Random.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

Solution Solution::initial(Graph &g) {
    std::vector<int> pi;

    pi.push_back(0);

    for (unsigned int i = 1; i < g.edges.size(); i++) {
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

    for (unsigned int i = 1; i < g.edges.size(); i++) {
        for (unsigned int j = i + 1; j < g.edges.size(); j++) {
            cost += g.edges[pi[i]][pi[j]];
        }
    }

    return cost;
}

Solution Solution::shuffle(Graph &g) {
    std::vector<int> pi_prime = this->pi;

    std::random_shuffle(pi_prime.begin() + 1, pi_prime.end());

    return Solution(pi_prime, g);
}