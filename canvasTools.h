#ifndef CANVAS_TOOLS
#define CANVAS_TOOLS

#include "canvas.h"
#include "debug.h"
#include "entryHolder.h"
#include "squareState.h"

bool fillEntries(Canvas* canvas, bool isRow, int size, int index, int start, int end, SQUARE_STATE state) {
    bool didUpdate = false;

    if (start < 0 || end > size) {
        string entryIsRow = isRow ? "row" : "column";
        cerr << "updating " << entryIsRow << " past it's size: " << size << "start: " << start << " end: " << end << endl;
        return false;
    }

    if (isRow) {
        for (int i = start; i != end + 1; i++) {
            if (canvas->getCanvas()[(index*size) + i] == EMPTY) {
                log("updating entry: " + to_string((index*size) + i) + " to: " + squareStateToPrettyString(state));
                canvas->getCanvas()[(index*size) + i] = state;
                didUpdate = true;
            } else if (state != canvas->getCanvas()[(index*size) + i]) {
                log("invalid row update at: " + to_string((index*size) + i) + " from state: " +
                squareStateToPrettyString(canvas->getCanvas()[(index*size) + i]) + " to state: " +
                squareStateToPrettyString(state));
            }
        }
    } else {
        for (int i = start; i != end + 1; i++) {
            if (canvas->getCanvas()[(size*i) + index] == EMPTY) {
                log("updating entry: " + to_string((size*i) + index) + " to: " + squareStateToPrettyString(state));
                canvas->getCanvas()[(size*i) + index] = state;
                didUpdate = true;
            } else if (state != canvas->getCanvas()[(size*i) + index]) {
                log("invalid row update at: " + to_string((size*i) + index) + " from state: " +
                squareStateToPrettyString(canvas->getCanvas()[(size*i) + index]) + " to state: " +
                squareStateToPrettyString(state));
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

int findSpaceBetweenCrosses(Canvas* canvas, bool isRow, int size, int index, int space) {
    int count = 0;
    bool foundSpace = false;
    int endIndex = -1;

    if (isRow) {
        for (int i = 0; i < size; i++) {
            int state = canvas->getCanvas()[(index*size) + i];
            if (count > space) {
                return -1;
            }
            if (state == CROSS) {
                if (count == space) {
                    if (!foundSpace) {
                        foundSpace = true;
                        endIndex = i;
                    } else {
                        // already been found so not unique
                        endIndex = -1;
                    }
                }
                count = 0;
            } else {
                count++;
            }
        }
    } else {
        for (int i = 0; i < size; i++) {
            int state = canvas->getCanvas()[(size*i) + index];
            if (count > space) {
                return -1;
            }
            if (state == CROSS) {
                if (count == space) {
                    if (!foundSpace) {
                        foundSpace = true;
                        endIndex = i;
                    } else {
                        // already been found so not unique
                        endIndex = -1;
                    }
                }
                count = 0;
            } else {
                count++;
            }
        }
    }

    if (count == space) {
        if (!foundSpace) {
            foundSpace = true;
            endIndex = size-1;
        } else {
            // already been found so not unique
            endIndex = -1;
        }
    }
    return endIndex;
}

#endif