#ifndef RELOCATERIGHTMOVE_H
#define RELOCATERIGHTMOVE_H


#include "Move.h"

class RelocateRightMove : public Move {
    int i;
    int j;

    int evaluate(Graph &g, Solution &s);

    void move(Graph &g, Solution &s);
};


#endif
