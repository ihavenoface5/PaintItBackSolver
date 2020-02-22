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

    if (holder->getNumEntries() > 1) {
        log("Rule doesn't apply to > 1 entry");
        return false;
    }

    int entry = holder->getEntries()[0].getValue();

    int endIndex = findSpaceBetweenCrosses(canvas, holder->getIsRow(), holder->getSize(), holder->getIndex(), entry);

    if (endIndex != -1) {
        return fillEntries(canvas, holder->getIsRow(), holder->getSize(), holder->getIndex(), endIndex - entry, endIndex, BLACK);
    }

    return false;
}

#endif