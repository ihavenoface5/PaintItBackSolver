#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>
#include "squareState.h"

class Canvas {
    private:
        int* canvas;
        int numRows;
        int numColumns;

    public:
        Canvas(int rows, int columns);
        int* getCanvas() { return this->canvas; };
        void print();
};

Canvas::Canvas(int rows, int columns) {
    this->numRows = rows;
    this->numColumns = columns;
    this->canvas = new int[rows * columns]{EMPTY};
}

void Canvas::print() {
    for (int i = 0; i < this->numRows; i++) {
        for (int j = 0; j < this->numColumns; j++) {
            cout << squareStateToString(this->canvas[(i * numColumns) + j]) << " ";
        }
        cout << endl;
    }
}

#endif