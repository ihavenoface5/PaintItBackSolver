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
        int size;
        int blackCount;
        bool isMarked;
        bool isRow;
        int index;

    public:
        void setEntries(string entryString);
        void setIsMarked(bool isMarked);
        void setSize(int size) { this->size = size; };
        void setIsRow(bool isRow) { this->isRow = isRow; };
        void setIndex(int index) { this->index = index; };
        void printEntries();
        int getNumEntries() { return this->numEntries; };
        int getSize() { return this->size; };
        Entry* getEntries() { return this->entries; };
        int getIndex() { return this->index; };
        bool getIsRow() { return this->isRow; };
        int getBlackCount() { return this->blackCount; };
        bool getIsMarked() { return this->isMarked; };
        EntryHolder();
        ~EntryHolder();
};

EntryHolder::EntryHolder() {
    this->isMarked = false;
    this->blackCount = 0;
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
        this->blackCount += entryValue;
    }
}

void EntryHolder::setIsMarked(bool isMarked) {
    this->isMarked = isMarked;
    if (isMarked) {
        for (int i = 0; i < this->numEntries; i++) {
            this->entries[i].setIsMarked(true);
        }
    }
}

void EntryHolder::printEntries() {
    cout << "isRow: " << to_string(this->isRow) << endl;
    cout << "index: " << to_string(this->index) << endl;
    cout << "isMarked: " << to_string(this->isMarked) << endl;
    for (int i = 0; i < this->numEntries; i++) {
        cout << this->entries[i].toString() << endl;
    }
}

EntryHolder::~EntryHolder() {
    delete [] this->entries;
}

#endif