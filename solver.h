#ifndef SOLVER_H
#define SOLVER_H

#include "Rules/ruleDefinitions.h"
#include "painting.h"
#include "canvas.h"
#include "debug.h"

class Solver {
    private:
        Painting* painting;
        Canvas* canvas;
        bool runRules(int numRows, EntryHolder* rows, int numColumns, EntryHolder* columns);

    public:
        Solver(Painting* painting, Canvas* canvas);
        Painting* getPainting() { return this->painting; };
        Painting* process();
        void printRules();
};

Solver::Solver(Painting* painting, Canvas* canvas) {
    this->painting = painting;
    this->canvas = canvas;
}

Painting* Solver::process() {
    int numRows = painting->getNumRows();
    EntryHolder* rows = painting->getRows();
    int numColumns = painting->getNumColumns();
    EntryHolder* columns = painting->getColumns();
    while (Solver::runRules(numRows, rows, numColumns, columns)) {

    }
}

bool Solver::runRules(int numRows, EntryHolder* rows, int numColumns, EntryHolder* columns) {
    bool didUpdate = false;
    
    log("ROWS++++++++++++++++++++++++++++++++++++++++++");
    for (int i = 0; i < NUM_RULES; i++) {
        ruleFunction function = ALL_RULES[i].getRunMethod();
        for (int j = 0; j < numRows; j++) {
            bool result = function(&rows[j], this->canvas);
            if (result) {
                log("row was updated");
                didUpdate = true;
            } else {
                log("row remains unchanged");
            }
        }
    }

    log("COLUMNS++++++++++++++++++++++++++++++++++++++++++");
    for (int i = 0; i < NUM_RULES; i++) {
        ruleFunction function = ALL_RULES[i].getRunMethod();
        for (int j = 0; j < numColumns; j++) {
            bool result = function(&columns[j], this->canvas);
            if (result) {
                log("column was updated");
                didUpdate = true;
            } else {
                log("column remains unchanged");
            }
        }
    }

    return didUpdate;
}

void Solver::printRules() {
    log("ALL RULES");

    for(int i = 0; i < NUM_RULES; i++) {
        log(ALL_RULES[i].toString());
    }
}

#endif