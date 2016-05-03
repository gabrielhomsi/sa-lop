#include "ShiftRightMove.h"
#include "../Random.h"

using namespace std;

int ShiftRightMove::evaluate(Graph &g, Solution &s) {
    i = util::random_int(0, (int) s.pi.size() - 2);
    j = i + 1;

    delta = g.edges[s.pi[j]][s.pi[i]] - g.edges[s.pi[i]][s.pi[j]];

    return delta;
}

void ShiftRightMove::move(Graph &g, Solution &s) {
    swap(s.pi[i], s.pi[j]);

    s.cost += delta;
}
