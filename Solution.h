#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>

class Solution {
public:
    std::vector<int> pi;
    int cost;

    static Solution initial(std::vector<std::vector<int>> &C);

    Solution(std::vector<int> pi, std::vector<std::vector<int>> &C);

    Solution(std::vector<int> pi, int cost);

    int evaluate(std::vector<std::vector<int>> &C);

    Solution neighbor(std::vector<std::vector<int>> &C);
};


#endif
