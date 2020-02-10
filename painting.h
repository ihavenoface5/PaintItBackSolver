#ifndef PAINTING_H
#define PAINTING_H

#include <iostream>
#include "entryHolder.h"
#include "squareState.h"
using namespace std;

using Row = EntryHolder;
using Column = EntryHolder;

class Painting {
    private:
        int numRows;
        int numColumns;
        Row* rows;
        Column* columns;
        int* canvas;
        void initializeCanvas();
        void cleanUp();

    public:
        Painting(int rows, int columns);
        void printCanvas();
        void printRowsAndColumns();
        void setRows(string* rows);
        void setColumns(string* columns);
        ~Painting();
};


Painting::Painting(int rows, int columns) {
    this->numRows = rows;
    this->numColumns = columns;
    this->initializeCanvas();
}

void Painting::setRows(string* rows) {
    this->rows = new Row[this->numRows];
    for (int i = 0; i < this->numRows; i++) {
        this->rows[i].setEntries(rows[i]);
    }
}

void Painting::setColumns(string* columns) {
    this->columns = new Column[this->numColumns];
    for (int i = 0; i < this->numColumns; i++) {
        this->columns[i].setEntries(columns[i]);
    }
}

void Painting::initializeCanvas() {
    this->canvas = new int[this->numRows * this->numColumns]{EMPTY};
}

void Painting::printCanvas() {
    for (int i = 0; i < this->numRows; i++) {
        for (int j = 0; j < this->numColumns; j++) {
            cout << squareStateToString(this->canvas[(i + 1) * j]) << " ";
        }
        cout << endl;
    }
}

void Painting::printRowsAndColumns() {
    for (int i = 0; i < this->numRows; i++) {
        cout << "Row: " << to_string(i+1) << endl;
        this->rows[i].printEntries();
    }

    for (int i = 0; i < this->numColumns; i++) {
        cout << "Column: " << to_string(i+1) << endl;
        this->columns[i].printEntries();
    }
}

void Painting::cleanUp() {
    delete [] this->canvas;
    delete [] this->rows;
    delete [] this->columns;
}

Painting::~Painting() {
    this->cleanUp();
}

#endif