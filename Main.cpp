#include <iostream>
#include <iomanip>
#include <vector>
#include "SimulatedAnnealing.h"

using namespace std;

int main() {
    int N;

    cin >> N;

    vector<vector<int>> C;
    C.resize(N + 1);

    for (unsigned int i = 1; i < C.size(); i++) {
        C[i].resize(C.size());
    }

    for (unsigned int i = 1; i < C.size(); i++) {
        for (unsigned int j = 1; j < C[i].size(); j++) {
            cin >> C[i][j];
        }
    }

    double T = 4;
    double decay_factor = 0.99;
    int iterations = 250;

    SimulatedAnnealing sa(C, T, decay_factor, iterations);

    Solution w = Solution::initial(C);
    Solution w_prime = sa.run(w);

    cout << "Initial cost = " << w.cost << endl;
    cout << "__Final cost = " << w_prime.cost << endl;
    cout << "_Improvement = " << ((double) w_prime.cost) / w.cost << endl;

    return 0;
}