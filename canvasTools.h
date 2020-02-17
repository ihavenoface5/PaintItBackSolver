#ifndef CANVAS_TOOLS
#define CANVAS_TOOLS

#include "canvas.h"
#include "debug.h"
#include "entryHolder.h"
#include "squareState.h"

bool fillEntries(Canvas* canvas, bool isRow, int size, int index, int start, int end, SQUARE_STATE state) {
    bool didUpdate = false;

    if (isRow) {
        for (int i = start; i != end + 1; i++) {
            if (canvas->getCanvas()[(index*size) + i] == EMPTY) {
                log("updating entry: " + to_string((index*size) + i) + " to: " + squareStateToPrettyString(state));
                canvas->getCanvas()[(index*size) + i] = state;
                didUpdate = true;
            }
        }
    } else {
        for (int i = start; i != end + 1; i++) {
            if (canvas->getCanvas()[(size*i) + index] == EMPTY) {
                log("updating entry: " + to_string((size*i) + index) + " to: " + squareStateToPrettyString(state));
                canvas->getCanvas()[(size*i) + index] = state;
                didUpdate = true;
            }
        }
    }

    return didUpdate;
}

int countBlackInRowOrColumn(Canvas* canvas, bool isRow, int size, int index) {
    int count = 0;
    if (isRow) {
        for (int i = 0; i < size; i++) {
            if (canvas->getCanvas()[(index*size) + i] == BLACK) {
                count++;
            }
        }
    } else {
        for (int i = 0; i < size; i++) {
            if (canvas->getCanvas()[(size*i) + index] == BLACK) {
                count++;
            }
        }
    }
    return count;
}

int largestSpaceBetweenCrosses(Canvas* canvas, bool isRow, int size, int index) {
    int largestCount = 0;
    int count = 0;

    if (isRow) {
        for (int i = 0; i < size; i++) {
            int state = canvas->getCanvas()[(index*size) + i];
            if (state == CROSS) {
                largestCount = count;
                count = 0;
            } else {
                count++;
            }
        }
    } else {
        for (int i = 0; i < size; i++) {
            int state = canvas->getCanvas()[(size*i) + index];
            if (state == CROSS) {
                largestCount = count;
                count = 0;
            } else {
                count++;
            }
        }
    }

    if (count > largestCount) {
        return count;
    }

    return largestCount;
}

#endif