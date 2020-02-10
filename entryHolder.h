#ifndef ENTRY_HOLDER_H
#define ENTRY_HOLDER_H

#include <string>
#include <algorithm>
#include <iostream>
#include "entry.h"
#include "utilities.h"
using namespace std;

class EntryHolder {
    private:
        Entry* entries;
        int numEntries;
        bool isMarked;
    public:
        void setIsMarked(bool marked) { this->isMarked = marked; };
        void setEntries(string entryString);
        void printEntries();
        EntryHolder();
};

EntryHolder::EntryHolder() {
    this->isMarked = false;
}

void EntryHolder::setEntries(string entryString) {
    int numOfEntries = count(entryString.begin(), entryString.end(), ',');
    numOfEntries++;
    this->numEntries = numOfEntries;
    this->entries = new Entry[numOfEntries];
    string* entries = explode(entryString, ',', numOfEntries);

    for (int i = 0; i < numOfEntries; i++) {
        int entryValue = stoi(entries[i]);
        this->entries[i].setValue(entryValue);
    }
}

void EntryHolder::printEntries() {
    for (int i = 0; i < this->numEntries; i++) {
        cout << this->entries[i].toString() << endl;
    }
}

#endif