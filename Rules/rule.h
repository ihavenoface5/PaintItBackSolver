#ifndef RULE_H
#define RULE_H

#include <string>
#include "../entryHolder.h"
using namespace std;

typedef void (*ruleFunction)(EntryHolder*);

class Rule {
    private:
        string description;
        ruleFunction run;
    public:
        Rule(string description, ruleFunction run);
        string getDescription(){ return this->description; };
        string toString() const { return this->description; };
        ruleFunction getRunMethod() const { return this->run; };
};

Rule::Rule(string description, ruleFunction run) {
    this->description = description;
    this->run = run;
}

#endif