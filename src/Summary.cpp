#include <iostream>
#include "Summary.h"

Summary::Summary(Graph &g) {
    this->g = g;
}

void Summary::show(Solution initial_w, Solution best_w) {
    double improvement = (((double) best_w.cost) / initial_w.cost) - 1;

//    std::cout << "Initial cost = " << initial_w.cost << std::endl;
//    std::cout << "__Final cost = " << best_w.cost << std::endl;
//    std::cout << "_Improvement = " << improvement << std::endl;

    std::cout << best_w.cost << ", " << improvement << ", ";

//    if (best_w.cost != best_w.evaluate(g)) {
//        std::cout << "WARNING! w.cost != w.evaluate(C)" << std::endl;
//    }
}
