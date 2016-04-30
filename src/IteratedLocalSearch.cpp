#include <iostream>
#include "IteratedLocalSearch.h"
#include "LocalSearch.h"
#include "Random.h"

IteratedLocalSearch::IteratedLocalSearch(Graph g, int iterations, int ls_move_strategy) {
    this->g = g;
    this->iterations = iterations;
    this->ls_move_strategy = ls_move_strategy;
    this->parameters = Parameters::getInstance();
}

Solution IteratedLocalSearch::run(Solution s0) {
    std::cout << "[ILS] " << std::endl;

    LocalSearch localSearch(g, ls_move_strategy);

    Solution s_star = localSearch.run(s0);

    int i = iterations;

    do {
        if (!parameters.silent) {
            std::cout << "[ILS] " << std::endl;
        }

        Solution s_prime = perturbation(s_star);
        Solution s_star_prime = localSearch.run(s_prime);

        if (acceptanceCriterion(s_star, s_star_prime)) {
            s_star = s_star_prime;
        };

        i--;
    } while (i > 0);

    return s_star;
}

Solution IteratedLocalSearch::perturbation(Solution s_star) {
    int i;
    int j;

    do {
        i = util::random_int(1, (int) s_star.pi.size() - 1);
        j = util::random_int(1, (int) s_star.pi.size() - 1);
    } while (i >= j);

    std::swap(s_star.pi[i], s_star.pi[j]);

    s_star.cost = s_star.evaluate(g);

    return s_star;
}

bool IteratedLocalSearch::acceptanceCriterion(Solution &s_star, Solution &s_star_prime) {
    // Better
    return s_star_prime.cost > (1) * s_star.cost;
}
