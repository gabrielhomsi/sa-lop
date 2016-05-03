#include "ShiftLeftMove.h"
#include "../Random.h"

using namespace std;

int ShiftLeftMove::evaluate(Graph &g, Solution &s) {
    i = util::random_int(1, (int) s.pi.size() - 1);
    j = i - 1;

    delta = g.edges[s.pi[i]][s.pi[j]] - g.edges[s.pi[j]][s.pi[i]];

    return delta;
}

void ShiftLeftMove::move(Graph &g, Solution &s) {
    swap(s.pi[i], s.pi[j]);

    s.cost += delta;
}
