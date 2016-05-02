#include <iostream>
#include <iomanip>
#include "Graph.h"
#include "Parameters.h"
#include "SimulatedAnnealing.h"
#include "Summary.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv) {
    Parameters &parameters = Parameters::getInstance();
    parameters.load(argc, argv);

    Graph g;

    g.read();

    Summary summary(g);

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    if (parameters.vm.count("sa")) {
        double T = parameters.vm["sa-temperature"].as<double>();
        double decay_factor = parameters.vm["sa-decay-factor"].as<double>();
        int iterations = parameters.vm["sa-iterations"].as<int>();

        SimulatedAnnealing sa(g, T, decay_factor, iterations);

        Solution initial_w = Solution::initial(g);
        Solution best_w = sa.run(initial_w);

        summary.show(best_w, t1);
    }

    return 0;
}