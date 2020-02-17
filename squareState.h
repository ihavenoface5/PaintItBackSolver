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
            return "ERROR";           
    }
}

string squareStateToPrettyString(int state) {
    switch(state) {
        case EMPTY:
            return "EMPTY";
        case BLACK:
            return "BLACK";
        case CROSS:
            return "CROSS";
        default:
            return "ERROR";       
    }
}

#endif