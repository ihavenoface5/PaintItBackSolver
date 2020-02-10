#ifndef ENTRY_H
#define ENTRY_H

#include <string>
using namespace std;

class Entry {
    private:
        int value;
        bool isMarked;
    public:
        void setIsMarked(bool marked) { this-> isMarked = marked; };
        void setValue(int value) { this->value = value; };
        string toString();
        Entry();
};

Entry::Entry() {
    this->isMarked = false;
}

string Entry::toString() {
    return "Entry value: " + to_string(this->value) + " isMarked: " + to_string(this->isMarked);
}

#endif