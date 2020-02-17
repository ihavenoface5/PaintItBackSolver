#ifndef RULE_DEFINITIONS_H
#define RULE_DEFINITIONS_H

#include <string>
#include "rule.h"
#include "bigNumberRule.h"
#include "markWhereDoneRule.h"
#include "onlyPlaceItFitsRule.h"
using namespace std;

#define NUM_RULES 3

const string BIG_NUMBER_RULE_DESC = "Entries with a large number can be filled in if big enough.";
const string MARK_WHERE_DONE_RULE_DESC = "Mark squares where entries or complete rows are done.";
const string ONLY_PLACE_IT_FITS_RULE_DESC = "Mark the place where the entry has to go given surrounding squares.";

const Rule bigNumberRule = Rule(BIG_NUMBER_RULE_DESC, bigNumberRuleFunction);
const Rule markWhereDoneRule = Rule(MARK_WHERE_DONE_RULE_DESC, markWhereDoneFunction);
const Rule onlyPlaceItFitsRule = Rule(ONLY_PLACE_IT_FITS_RULE_DESC, onlyPlaceItFitsFunction);

const Rule ALL_RULES[] = {
    bigNumberRule,
    markWhereDoneRule,
    onlyPlaceItFitsRule,
};

#endif