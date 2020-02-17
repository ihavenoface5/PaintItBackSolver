#ifndef DEBUG_H
#define DEBUG_H

#include <string>
#include <iostream>
using namespace std;

#define DEBUG 0

void log(string message) {
    if (DEBUG) {
        cout << message << endl;    
    }
}

#endif