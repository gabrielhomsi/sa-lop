#include "SimulatedAnnealing.h"
#include "Solution.h"
#include "Random.h"
#include "Parameters.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

SimulatedAnnealing::SimulatedAnnealing(Graph &g, double T, double decay_factor,
                                       int iterations) {
    this->g = g;
    this->T = T;
    this->decay_factor = decay_factor;
    this->iterations = iterations;
    this->parameters = Parameters::getInstance();
}

Solution SimulatedAnnealing::run(Solution s_initial) {
    double e = 2.718281828459045;

    Solution s = s_initial;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for (double temperature = this->T; temperature > 1; temperature *= this->decay_factor) {
        for (int m = 0; m < this->iterations; m++) {
            int i;
            int j;

            int neighborhood_type = util::random_int(1, 4);

            if (neighborhood_type == 1) { // relocateRight
                i = util::random_int(0, (int) s.pi.size() - 2);
                j = util::random_int(i + 1, (int) s.pi.size() - 1);
            } else if (neighborhood_type == 2) { // relocateLeft
                i = util::random_int(1, (int) s.pi.size() - 1);
                j = util::random_int(0, i - 1);
            } else if (neighborhood_type == 3 || neighborhood_type == 4) { // shiftRight
                i = util::random_int(0, (int) s.pi.size() - 2);
                j = i + 1;
            } else if (neighborhood_type == 5 || neighborhood_type == 6) { // shiftLeft
                i = util::random_int(1, (int) s.pi.size() - 1);
                j = i - 1;
            } else {
                cout << "WARNING! unrecognized neighborhood type" << endl;

                exit(1);
            }

            int delta = 0;

            if (i < j) { // Delta for relocateRight / shiftRight
                for (int k = i + 1; k <= j; k++) {
                    delta += g.edges[s.pi[k]][s.pi[i]] - g.edges[s.pi[i]][s.pi[k]];
                }
            } else { // Delta for relocateLeft / shiftLeft
                for (int k = j; k >= i; k--) {
                    delta += g.edges[s.pi[k]][s.pi[i]] - g.edges[s.pi[i]][s.pi[k]];
                }
            }

            if (delta >= 0) {
                if (i < j) { // relocateRight shiftRight
                    for (int k = i + 1; k <= j; k++) {
                        swap(s.pi[k - 1], s.pi[k]);
                    }
                } else { // relocateLeft / shiftLeft
                    for (int k = j; k >= i; k--) {
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

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(t2 - t1).count() * 1e-6;

    cout << parameters.vm["instance"].as<string>() << " " <<
            T << " " <<
            decay_factor << " " <<
            iterations << " " <<
            s.cost << " " <<
            duration << endl;

    if (s.cost != s.evaluate(g)) {
        cout << "WARNING! s.cost != s.evaluate(C)" << endl;
    }

    return s;
}