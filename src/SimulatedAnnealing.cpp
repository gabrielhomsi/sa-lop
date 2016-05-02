#include "SimulatedAnnealing.h"
#include "Solution.h"
#include "Random.h"
#include "Parameters.h"
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

SimulatedAnnealing::SimulatedAnnealing(Graph &g, double T, double decay_factor,
                                       int iterations) {
    this->g = g;
    this->T = T;
    this->decay_factor = decay_factor;
    this->iterations = iterations;
    this->parameters = Parameters::getInstance();
}

Solution SimulatedAnnealing::run(Solution s) {
    double e = 2.718281828459045;

    for (double temperature = this->T; temperature > 1; temperature *= this->decay_factor) {
        for (int m = 0; m < this->iterations; m++) {
            int i;
            int j;

            do {
                i = util::random_int(0, (int) s.pi.size() - 1);
                j = util::random_int(0, (int) s.pi.size() - 1);
            } while (i == j);

            int delta = 0;

            if (i < j) { // Delta for relocateRight
                for (int k = i + 1; k < j; k++) {
                    delta += g.edges[s.pi[k]][s.pi[i]] - g.edges[s.pi[i]][s.pi[k]];
                }
            } else { // Delta for relocateLeft
                for (int k = j; k > i; k--) {
                    delta += g.edges[s.pi[k]][s.pi[i]] - g.edges[s.pi[i]][s.pi[k]];
                }
            }

            if (delta >= 0 || util::random_double() <= pow(e, delta / temperature)) {
                if (i < j) { // relocateRight
                    for (int k = i + 1; k < j; k++) {
                        swap(s.pi[k - 1], s.pi[k]);
                    }
                } else { // relocateLeft
                    for (int k = j; k > i; k--) {
                        swap(s.pi[k - 1], s.pi[k]);
                    }
                }

                s.cost += delta;

                if (!parameters.silent) {
                    cout << "[SA] " << s.cost << endl;
                }
            }
        }
    }

    return s;
}