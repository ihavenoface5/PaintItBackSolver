#ifndef SQUARE_STATE_H
#define SQUARE_STATE_H

#include <string>
using namespace std;

enum SQUARE_STATE {
    EMPTY,
    BLACK,
    CROSS
};

string squareStateToString(int state) {
    switch(state) {
        case EMPTY:
            return "!";
        case BLACK:
            return "@";
        case CROSS:
            return "X";
        default:
            break;            
    }
}

#endif