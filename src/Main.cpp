#include <iostream>
#include <iomanip>
#include "Graph.h"
#include "Parameters.h"
#include "SimulatedAnnealing.h"
#include "IteratedLocalSearch.h"
#include "LocalSearch.h"
#include "Summary.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv) {
    Graph g;

    g.read();

    Summary summary(g);

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    Parameters &parameters = Parameters::getInstance();
    parameters.load(argc, argv);

    if (parameters.vm.count("sa")) {
        double T = parameters.vm["sa-temperature"].as<double>();
        double decay_factor = parameters.vm["sa-decay-factor"].as<double>();
        int iterations = parameters.vm["sa-iterations"].as<int>();

        SimulatedAnnealing sa(g, T, decay_factor, iterations);

        Solution initial_w = Solution::initial(g);
        Solution best_w = sa.run(initial_w);

        cout << T << ", " << decay_factor << ", " << iterations << ", ";

        summary.show(initial_w, best_w);
    } else if (parameters.vm.count("ils")) {
        int iterations = parameters.vm["ils-iterations"].as<int>();
        int ls_move_strategy = parameters.vm["ils-ls-move-strategy"].as<int>();

        IteratedLocalSearch ils(g, iterations, ls_move_strategy);

        Solution initial_w = Solution::initial(g);
        Solution best_w = ils.run(initial_w);

        summary.show(initial_w, best_w);
    } else if (parameters.vm.count("ls")) {
        int move_strategy = parameters.vm["ls-move-strategy"].as<int>();

        LocalSearch localSearch(g, move_strategy);

        Solution initial_w = Solution::initial(g);
        Solution best_w = localSearch.run(initial_w);

        summary.show(initial_w, best_w);
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(t2 - t1).count();

//    cout << "Execution time: " << duration * 1e-6 << "s" << endl;

    cout << duration * 1e-6 << endl;

    return 0;
}