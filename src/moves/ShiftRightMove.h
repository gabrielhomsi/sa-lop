#ifndef SHIFTRIGHTMOVE_H
#define SHIFTRIGHTMOVE_H


#include "Move.h"

class ShiftRightMove : public Move {
    int i;
    int j;

    int evaluate(Graph &g, Solution &s);

    void move(Graph &g, Solution &s);
};


#endif
