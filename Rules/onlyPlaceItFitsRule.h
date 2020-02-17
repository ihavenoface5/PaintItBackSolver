#ifndef ONLY_PLACE_IT_FITS_RULE_H
#define ONLY_PLACE_IT_FITS_RULE_H

#include "../entryHolder.h"
#include "../canvas.h"
#include "../canvasTools.h"
#include "../squareState.h"
#include "../debug.h"

bool onlyPlaceItFitsFunction(EntryHolder* holder, Canvas* canvas) {
    if (holder->getIsMarked()) {
        log("Row or column already done.");
        return false;
    }

    bool didUpdate = false;

    int countBetweenCrosses = largestSpaceBetweenCrosses(canvas, holder->getIsRow(), holder->getSize(), holder->getIndex());

    for (int i = 0; i < holder->getNumEntries(); i++) {
        Entry* currentEntry = &holder->getEntries()[i];
        if (!currentEntry->getIsMarked() && currentEntry->getValue() == countBetweenCrosses) {
            if (fillEntries(canvas, holder->getIsRow(), holder->getSize(), holder->getIndex(), 0, holder->getSize()-1, BLACK)) {
                didUpdate = true;
            }
        }
    }

    return didUpdate;
}

#endif