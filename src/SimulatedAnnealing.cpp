#include "SimulatedAnnealing.h"
#include "Random.h"
#include "moves/ShiftLeftMove.h"
#include "moves/ShiftRightMove.h"
#include "moves/RelocateLeftMove.h"
#include "moves/RelocateRightMove.h"
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

    ShiftLeftMove shiftLeftMove;
    ShiftRightMove shiftRightMove;
    RelocateLeftMove relocateLeftMove;
    RelocateRightMove relocateRightMove;

    Move *moves[4] = {&shiftLeftMove, &shiftRightMove, &relocateLeftMove, &relocateRightMove};

    for (double temperature = this->T; temperature > 1e-1; temperature *= this->decay_factor) {
        for (int m = 0; m < this->iterations; m++) {
            int move_type = util::random_int(0, 3);

            Move *move = moves[move_type];

            int delta = move->evaluate(g, s);

            if (delta >= 0 || util::random_double() <= exp(delta / temperature)) {
                move->move(g, s);

                if (!parameters.silent) {
                    cout << "[SA] " << s.cost << endl;
                }
            }
        }
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(t2 - t1).count() * 1e-6;

    cout << parameters.vm["instance"].as<string>() << ", " <<
    T << ", " <<
    decay_factor << ", " <<
    iterations << ", " <<
    s.cost << ", " <<
    duration << endl;

    if (s.cost != s.evaluate(g)) {
        cout << "WARNING! s.cost != s.evaluate(C)" << endl;
    }

    return s;
}