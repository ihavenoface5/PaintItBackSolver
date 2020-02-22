#ifndef BIG_NUMBER_RULE_H
#define BIG_NUMBER_RULE_H

#include "../entryHolder.h"
#include "../debug.h"
#include "../canvas.h"
#include "../utilities.h"
#include "../canvasTools.h"
#include "../squareState.h"

bool bigNumberRuleFunction(EntryHolder* holder, Canvas* canvas) {
    log("Processing big number rule");

    if (holder->getIsMarked()) {
        log("Row or Column already complete");
        return false;
    }
    // determine if the rule should run
    if (holder->getNumEntries() != 1) {
        log("Rule not ran: # of entries != 1");
        return false;
    }

    int entry = holder->getEntries()[0].getValue();
    int size = holder->getSize();
    bool isRow = holder->getIsRow();
    int index = holder->getIndex();

    float half = size / 2.0f;
    if (entry < half + 1) {
        log("Rule not ran: size of entry < 1/2 of size");
        return false;
    }

    log("Row or Column should be updated");

    if (size == entry) {
        // fill in the whole row
        holder->setIsMarked(true);
        return fillEntries(canvas, isRow, size, index, 0, size-1, BLACK);
    } else {
        int startIndex = size - entry;
        int endIndex = entry;
        return fillEntries(canvas, isRow, size, index, startIndex, endIndex-1, BLACK);
    }
}

#endif