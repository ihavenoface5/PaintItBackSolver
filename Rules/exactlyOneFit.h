#ifndef EXACTLY_ONE_FIT
#define EXACTLY_ONE_FIT

#include "../debug.h"
#include "../entryHolder.h"
#include "../canvas.h"
#include "../canvasTools.h"

bool exactlyOneFitFunction(EntryHolder* holder, Canvas* canvas) {
    if (holder->getIsMarked()) {
        log("Row or column already done.");
        return false;
    }

    if (holder->getNumEntries() < 2) {
        log("Not enough entries to process");
        return false;
    }

    bool didUpdate = false;

    int entryHolderCount = 0;

    for (int i = 0; i < holder->getNumEntries()-1; i++) {
        entryHolderCount += holder->getEntries()[i].getValue();
        entryHolderCount++;
    }

    entryHolderCount += holder->getEntries()[holder->getNumEntries()-1].getValue();

    if (entryHolderCount == holder->getSize()) {
        int currentIndex = 0;
        for (int i = 0; i < holder->getNumEntries()-1; i++) {
            bool didUpdateBlack = fillEntries(canvas, holder->getIsRow(), holder->getSize(), holder->getIndex(), currentIndex, currentIndex + holder->getEntries()[i].getValue()-1, BLACK);
            currentIndex += holder->getEntries()[i].getValue()-1;
            bool didUpdateCross = fillEntries(canvas, holder->getIsRow(), holder->getSize(), holder->getIndex(), currentIndex, currentIndex + 1, CROSS);
            currentIndex += 1;
            if (didUpdateBlack || didUpdateCross) {
                didUpdate = true;
            }
        }
    }

    return didUpdate;
}

#endif