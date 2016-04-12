#ifndef UNTITLED_SOLUTION_H
#define UNTITLED_SOLUTION_H

#include <vector>

class Solution {
public:
    std::vector<int> pi;
    int cost;

    static Solution initial(std::vector<std::vector<int> > &C);

    Solution(std::vector<int> pi, int cost);

    Solution neighbor(std::vector<std::vector<int> > &C);
};


#endif //UNTITLED_SOLUTION_H
