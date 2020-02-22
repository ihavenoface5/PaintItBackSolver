#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "painting.h"
#include "utilities.h"
#include "canvas.h"
#include "solver.h"
#include "debug.h"
using namespace std;

Painting parseInput(string filename);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Please specify a filename." << endl;
        exit(0);
    }

    Painting painting = parseInput(string(argv[1]));
    Canvas* canvas = new Canvas(painting.getNumRows(), painting.getNumColumns());
    Solver solver = Solver(&painting, canvas);
    solver.process();
    canvas->print();
    delete canvas;
}

Painting parseInput(string filename) {
    cerr << "filename: " << filename << endl;
    if (filename.compare("") == 0) {
        cerr << "filename not specified" << endl;
        exit(0);
    }

    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        cerr << "failed to open file." << endl;
        exit(0);
    }

    string rowsLine;
    string columnsLine;

    getline(file, rowsLine);
    getline(file, columnsLine);

    string rowsString = rowsLine.substr(rowsLine.find("=") + 1, rowsLine.length()-1);
    int rows = stoi(rowsString);

    string colsString = columnsLine.substr(columnsLine.find("=") + 1, columnsLine.length()-1);
    int columns = stoi(colsString);

    log("rows: " + to_string(rows));
    log("columns: " + to_string(columns));

    Painting painting = Painting(rows, columns);

    string columnValuesLine;
    getline(file, columnValuesLine);

    string* columnEntries = explode(columnValuesLine, ' ', columns);
    painting.setColumns(columnEntries, columns);

    string* rowEntries = new string[rows];

    for (int i = 0; i < rows; i++) {
        string nextLine;
        getline(file, nextLine);
        rowEntries[i] = nextLine;
    }

    painting.setRows(rowEntries, rows);

    delete [] rowEntries;
    file.close();

    return painting;
}