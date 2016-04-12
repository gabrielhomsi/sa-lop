#include "Solution.h"
#include <cstdlib>

Solution Solution::initial(std::vector<std::vector<int> > &C) {
    std::vector<int> pi;

    pi.push_back(0);

    for (int i = 1; i < C.size(); i++) {
        pi.push_back(i);
    }

    int cost = 0;

    for (int i = 1; i < C.size(); i++) {
        for (int j = i + 1; j < C.size(); j++) {
            cost += C[pi[i]][pi[j]];
        }
    }

    return Solution(pi, cost);
}

Solution::Solution(std::vector<int> pi, int cost) {
    this->pi = pi;
    this->cost = cost;
}

Solution Solution::neighbor(std::vector<std::vector<int> > &C) {
    std::vector<int> pi_prime = this->pi;

    int i;
    int j;

    do {
        i = (int) (1 + (rand() % (pi_prime.size() - 1)));
        j = (int) (1 + (rand() % (pi_prime.size() - 1)));
    } while (i != j && i > j);

    int delta = 0;

    for (int k = i; k < j; k++) {
        delta += C[pi_prime[k + 1]][pi_prime[k]] - C[pi_prime[k]][pi_prime[k + 1]];

        std::swap(pi_prime[k], pi_prime[k + 1]);
    }

    int cost_prime = this->cost + delta;

    return Solution(pi_prime, cost_prime);
}