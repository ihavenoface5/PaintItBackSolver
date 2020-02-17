#ifndef BIG_NUMBER_RULE_H
#define BIG_NUMBER_RULE_H

#include "../entryHolder.h"
#include "../debug.h"

void bigNumberRuleFunction(EntryHolder* holder) {
    log("Processing big number rule");
    holder->printEntries();
}

#endif