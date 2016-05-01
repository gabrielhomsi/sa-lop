#include "Parameters.h"

#include <iostream>
#include <cstdlib>

using namespace std;

void Parameters::load(int argc, char** argv)
{
    po::options_description description("Metaheuristics for the Linear Ordering Problem");

    description.add_options()
            ("help", "Display this help text and exit")

            ("instance", po::value<string>()->required(), "Path to instance file")

            ("sa", "Simulated Annealing")
            ("sa-temperature", po::value<double>(), "Simulated Annealing initial temperature")
            ("sa-decay-factor", po::value<double>(), "Simulated Annealing decay factor")
            ("sa-iterations", po::value<int>(), "Simulated Annealing iterations")

            ("ils", "Iterated Local Search")
            ("ils-iterations", po::value<int>(), "ILS iterations")
            ("ils-ls-move-strategy", po::value<int>(), "ILS move strategy for the Local Search (1- First admissible, 2- Best move)")

            ("ls", "Local Search")
            ("ls-move-strategy", po::value<int>(), "LS move strategy (1- First admissible, 2- Best move)")

            ("silent", "Silent mode");

    po::store(po::command_line_parser(argc, argv).options(description).run(), vm);
    po::notify(vm);

    if (vm.count("help")) {
        cout << description << endl;

        exit(1);
    }

    silent = vm.count("silent");
}