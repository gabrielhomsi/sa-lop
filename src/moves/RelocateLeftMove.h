#ifndef RELOCATELEFTMOVE_H
#define RELOCATELEFTMOVE_H


#include "Move.h"

class RelocateLeftMove : public Move {
    int i;
    int j;

    int evaluate(Graph &g, Solution &s);

    void move(Graph &g, Solution &s);
};


#endif
