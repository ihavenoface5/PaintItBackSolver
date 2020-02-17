#ifndef RULE_DEFINITIONS_H
#define RULE_DEFINITIONS_H

#include <string>
#include "rule.h"
#include "bigNumberRule.h"
using namespace std;

#define NUM_RULES 1

const string BIG_NUMBER_RULE_DESC = "Entries with a large number can be filled in if big enough.";

const Rule bigNumberRule = Rule(BIG_NUMBER_RULE_DESC, bigNumberRuleFunction);
const Rule ALL_RULES[] = {
    bigNumberRule
};

#endif