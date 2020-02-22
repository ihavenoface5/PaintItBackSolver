#ifndef DEBUG_H
#define DEBUG_H

#include <string>
#include <iostream>
#include "canvas.h"
using namespace std;

#define DEBUG 0
#define PRINT_STEPS 1

void log(string message) {
    if (DEBUG) {
        cout << message << endl;    
    }
}

void printStep(bool isRow, int index, Canvas* canvas) {
    if (PRINT_STEPS) {
        if (isRow) {
            cout << "Updating row: " << index << endl;
        } else {
            cout << "Updating column: " << index << endl;
        }
        canvas->print();
    }
}

#endif