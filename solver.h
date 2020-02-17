#ifndef SOLVER_H
#define SOLVER_H

#include "Rules/ruleDefinitions.h"
#include "painting.h"
#include "debug.h"

class Solver {
    private:
        Painting* painting;

    public:
        Solver(Painting* painting);
        Painting* getPainting() { return this->painting; };
        Painting* process();
        void printRules();
};

Solver::Solver(Painting* painting) {
    this->painting = painting;
}

Painting* Solver::process() {
    EntryHolder* rows = this->getPainting()->getRows();
    for (int i = 0; i < NUM_RULES; i++) {
        ruleFunction runMethod = ALL_RULES[i].getRunMethod();
        runMethod(rows);
    }
}

void Solver::printRules() {
    log("ALL RULES");

    for(int i = 0; i < NUM_RULES; i++) {
        log(ALL_RULES[i].toString());
    }
}

#endif