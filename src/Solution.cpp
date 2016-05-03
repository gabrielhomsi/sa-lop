#include "Solution.h"
#include <iostream>
#include <boost/bind.hpp>

using namespace std;

Solution Solution::constructive(Graph &g) {
    vector<pair<int, double>> s;

    for (unsigned int i = 0; i < g.edges.size(); i++) {
        int numerator = 0;
        int denominator = 0;

        for (unsigned int k = 0; k < g.edges.size(); k++) {
            numerator += g.edges[i][k];
            denominator += g.edges[k][i];
        }

        double q = (double) numerator / denominator;

        s.push_back(make_pair(i, q));
    }

    std::sort(s.begin(), s.end(),
              boost::bind(&std::pair<int, double>::second, _1) > boost::bind(&std::pair<int, double>::second, _2));

    std::vector<int> pi;

    for (unsigned int i = 0; i < s.size(); i++) {
        pi.push_back(s[i].first);
    }

    return Solution(pi, g);
}

Solution::Solution(std::vector<int> pi, Graph &g) {
    this->pi = pi;
    this->cost = evaluate(g);
}

Solution::Solution(std::vector<int> pi, int cost) {
    this->pi = pi;
    this->cost = cost;
}

int Solution::evaluate(Graph &g) {
    int cost = 0;

    for (unsigned int i = 0; i < g.edges.size(); i++) {
        for (unsigned int j = i + 1; j < g.edges.size(); j++) {
            cost += g.edges[pi[i]][pi[j]];
        }
    }

    return cost;
}