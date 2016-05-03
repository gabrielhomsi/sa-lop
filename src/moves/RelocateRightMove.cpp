#include "RelocateRightMove.h"
#include "../Random.h"

using namespace std;

int RelocateRightMove::evaluate(Graph &g, Solution &s) {
    i = util::random_int(0, (int) s.pi.size() - 2);
    j = util::random_int(i + 1, (int) s.pi.size() - 1);

    delta = 0;

    for (int k = i + 1; k <= j; k++) {
        delta += g.edges[s.pi[k]][s.pi[i]] - g.edges[s.pi[i]][s.pi[k]];
    }

    return delta;
}

void RelocateRightMove::move(Graph &g, Solution &s) {
    for (int k = i + 1; k <= j; k++) {
        swap(s.pi[k - 1], s.pi[k]);
    }

    s.cost += delta;
}
