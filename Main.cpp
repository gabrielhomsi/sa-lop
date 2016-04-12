#include <iostream>
#include <vector>
#include <ctime>
#include "SimulatedAnnealing.h"

using namespace std;

int main() {
    srand(time(NULL));

    int N;

    cin >> N;

    vector<vector<int> > C;
    C.resize(N + 1);

    for (int i = 1; i < C.size(); i++) {
        C[i].resize(C.size());
    }

    for (int i = 1; i < C.size(); i++) {
        for (int j = 1; j < C[i].size(); j++) {
            cin >> C[i][j];
        }
    }

    SimulatedAnnealing sa(C, 4, 0.99, 250);
    cout << "Final Cost = " << sa.run();

    return 0;
}