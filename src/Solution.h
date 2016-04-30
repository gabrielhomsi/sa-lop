#ifndef SOLUTION_H
#define SOLUTION_H


#include <vector>
#include "Graph.h"

class Solution {
public:
    std::vector<int> pi;
    int cost;

    static Solution initial(Graph &g);

    Solution(std::vector<int> pi, Graph &g);

    Solution(std::vector<int> pi, int cost);

    int evaluate(Graph &g);

    Solution shuffle(Graph &g);
};


#endif
