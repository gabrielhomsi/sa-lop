#include <chrono>
#include <iostream>
#include <iomanip>
#include "Graph.h"
#include "SimulatedAnnealing.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv) {
    Parameters &parameters = Parameters::getInstance();
    parameters.load(argc, argv);

    Graph g;

    g.read();

    if (parameters.vm.count("sa")) {
        double T = parameters.vm["sa-temperature"].as<double>();
        double decay_factor = parameters.vm["sa-decay-factor"].as<double>();
        int iterations = parameters.vm["sa-iterations"].as<int>();

        SimulatedAnnealing sa(g, T, decay_factor, iterations);
        Solution s_initial = Solution::initial(g);

        sa.run(s_initial);
    }

    return 0;
}