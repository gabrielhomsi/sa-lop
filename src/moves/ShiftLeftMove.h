#ifndef SHIFTLEFTMOVE_H
#define SHIFTLEFTMOVE_H


#include "Move.h"

class ShiftLeftMove : public Move {
public:
    int i;
    int j;

    int evaluate(Graph &g, Solution &s);

    void move(Graph &g, Solution &s);
};


#endif
