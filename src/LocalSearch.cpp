#include <iostream>
#include "LocalSearch.h"
#include "Parameters.h"

LocalSearch::LocalSearch(Graph g, int move_strategy) {
    this->g = g;
    this->move_strategy = move_strategy;
    this->parameters = Parameters::getInstance();
}

Solution LocalSearch::run(Solution s_init) {
    Solution s = s_init;
    int cost = -1;

    while (s.cost > cost) {
        cost = s.cost;

        searchNeighborhood(s);

        if (!parameters.silent) {
            std::cout << "\t[LS] " << s.cost << std::endl;
        }
    }

    return s;
}

void LocalSearch::searchNeighborhood(Solution &s) {
    if (move_strategy == 1) {
        firstAdmissibleMoveStrategy(s);
    } else if (move_strategy == 2) {
        bestMoveStrategy(s);
    } else {
        if (!parameters.silent) {
            std::cout << "WARNING! unrecognized move_strategy option" << std::endl;
        }
    }
}

void LocalSearch::firstAdmissibleMoveStrategy(Solution &s) {
    for (unsigned int i = 1; i < s.pi.size() - 1; i++) {
        int delta = 0;

        for (unsigned int j = i + 1; j < s.pi.size() - 1; j++) {
            delta += g.edges[s.pi[j]][s.pi[i]] - g.edges[s.pi[i]][s.pi[j]];

            if (s.cost + delta > s.cost) {
                for (unsigned int k = i; k < j; k++) {
                    s.cost += g.edges[s.pi[k + 1]][s.pi[k]] - g.edges[s.pi[k]][s.pi[k + 1]];

                    std::swap(s.pi[k], s.pi[k + 1]);
                }

                return;
            }
        }
    }
}

void LocalSearch::bestMoveStrategy(Solution &s) {
    int i_star = 1;
    int j_star = 1;
    int delta_star = 0;

    for (unsigned int i = 1; i < s.pi.size() - 1; i++) {
        int delta = 0;

        for (unsigned int j = i + 1; j < s.pi.size() - 1; j++) {
            delta += g.edges[s.pi[j]][s.pi[i]] - g.edges[s.pi[i]][s.pi[j]];

            if (delta > delta_star) {
                i_star = i;
                j_star = j;

                delta_star = delta;
            }
        }
    }

    for (int k = i_star; k < j_star; k++) {
        s.cost += g.edges[s.pi[k + 1]][s.pi[k]] - g.edges[s.pi[k]][s.pi[k + 1]];

        std::swap(s.pi[k], s.pi[k + 1]);
    }
}
