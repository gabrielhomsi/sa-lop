#include <iostream>
#include "Summary.h"

using namespace std;

Summary::Summary(Graph &g) {
    this->g = g;
    this->parameters = Parameters::getInstance();
}

void Summary::show(Solution best_w, high_resolution_clock::time_point t1) {
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(t2 - t1).count() * 1e-6;

    std::cout << parameters.vm["instance"].as<string>() << ", " << best_w.cost << ", " << duration << endl;

    if (best_w.cost != best_w.evaluate(g)) {
        std::cout << "WARNING! w.cost != w.evaluate(C)" << std::endl;
    }
}
