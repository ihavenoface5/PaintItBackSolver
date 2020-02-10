#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "painting.h"
#include "utilities.h"
using namespace std;

#define INPUT_FILENAME "input.txt"

Painting parseInput(string filename);

int main(int argc, char* argv[]) {
    Painting painting = parseInput(INPUT_FILENAME);
    painting.printCanvas();
    painting.printRowsAndColumns();
}

Painting parseInput(string filename) {
    if (filename.compare("") == 0) {
        cout << "filename not specified" << endl;
        exit(0);
    }

    ifstream file;
    file.open(filename);

    string rowsLine;
    string columnsLine;

    getline(file, rowsLine);
    getline(file, columnsLine);

    string rowsString = rowsLine.substr(rowsLine.find("=") + 1, rowsLine.length()-1);
    int rows = stoi(rowsString);

    string colsString = columnsLine.substr(columnsLine.find("=") + 1, columnsLine.length()-1);
    int columns = stoi(colsString);

    cout << "rows: " << rows << endl;
    cout << "columns: " << columns << endl;

    Painting painting = Painting(rows, columns);

    string rowEntryLine;
    getline(file, rowEntryLine);

    string* rowEntries = explode(rowEntryLine, ' ', rows);
    painting.setRows(rowEntries);

    string* columnEntries = new string[columns];

    for (int i = 0; i < columns; i++) {
        string nextLine;
        getline(file, nextLine);
        columnEntries[i] = nextLine;
    }

    painting.setColumns(columnEntries);

    file.close();

    return painting;
}