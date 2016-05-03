#include "RelocateLeftMove.h"
#include "../Random.h"

using namespace std;

int RelocateLeftMove::evaluate(Graph &g, Solution &s) {
    i = util::random_int(1, (int) s.pi.size() - 1);
    j = util::random_int(0, i - 1);

    delta = 0;

    for (int k = j; k >= i; k--) {
        delta += g.edges[s.pi[k]][s.pi[i]] - g.edges[s.pi[i]][s.pi[k]];
    }

    return delta;
}

void RelocateLeftMove::move(Graph &g, Solution &s) {
    for (int k = j; k >= i; k--) {
        swap(s.pi[k - 1], s.pi[k]);
    }

    s.cost += delta;
}
