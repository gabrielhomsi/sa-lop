#include "Solution.h"
#include "Random.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

Solution Solution::initial(std::vector<std::vector<int>> &C) {
    std::vector<int> pi;

    pi.push_back(0);

    for (unsigned int i = 1; i < C.size(); i++) {
        pi.push_back(i);
    }

    return Solution(pi, C);
}

Solution::Solution(std::vector<int> pi, std::vector<std::vector<int>> &C) {
    this->pi = pi;
    this->cost = evaluate(C);
}

Solution::Solution(std::vector<int> pi, int cost) {
    this->pi = pi;
    this->cost = cost;
}

int Solution::evaluate(std::vector<std::vector<int>> &C) {
    int cost = 0;

    for (unsigned int i = 1; i < C.size(); i++) {
        for (unsigned int j = i + 1; j < C.size(); j++) {
            cost += C[pi[i]][pi[j]];
        }
    }

    return cost;
}

Solution Solution::neighbor(std::vector<std::vector<int>> &C) {
    std::vector<int> pi_prime = this->pi;

    int cost_prime;

    int i;
    int j;

    do {
        i = util::random_int(1, (int) pi_prime.size() - 1);
        j = util::random_int(1, (int) pi_prime.size() - 1);
    } while (i != j && i > j);

    int delta = 0;

    for (int k = i; k < j; k++) {
        delta += C[pi_prime[k + 1]][pi_prime[k]] - C[pi_prime[k]][pi_prime[k + 1]];

        std::swap(pi_prime[k], pi_prime[k + 1]);
    }

    cost_prime = this->cost + delta;

    return Solution(pi_prime, cost_prime);
}