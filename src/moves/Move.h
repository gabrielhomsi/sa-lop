#ifndef MOVE_H
#define MOVE_H

#include "../Graph.h"
#include "../Solution.h"

class Move {
public:
    virtual int evaluate(Graph &g, Solution &s) = 0;

    virtual void move(Graph &g, Solution &s) = 0;

protected:
    int delta;
};

#endif
