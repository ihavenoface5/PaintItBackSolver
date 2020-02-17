#ifndef MARK_WHERE_DONE_RULE
#define MARK_WHERE_DONE_RULE

#include "../entryHolder.h"
#include "../canvas.h"
#include "../canvasTools.h"
#include "../squareState.h"

bool markWhereDoneFunction(EntryHolder* holder, Canvas* canvas) {
    bool didUpdate = false;
    for (int i = 0; i < holder->getNumEntries(); i++) {
        // is the entryholder done?
        int countInCanvas = countBlackInRowOrColumn(canvas, holder->getIsRow(), holder->getSize(), holder->getIndex());
        int countInEntry = holder->getBlackCount();

        // if it is, mark everything in the row
        if (countInCanvas == countInEntry) {
            if (fillEntries(canvas, holder->getIsRow(), holder->getSize(), holder->getIndex(), 0, holder->getSize()-1, CROSS)) {
                didUpdate = true;
                holder->setIsMarked(true);
            }
        }
    }
    return didUpdate;
}

#endif