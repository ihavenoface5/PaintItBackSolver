#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <sstream>
#include <utility>
using namespace std;

string* explode(string s, char delim, int size)
{
    string* result = new string[size];
    istringstream iss(s);

    for (int i = 0; i < size; i++)
    {
        getline(iss, result[i], delim);
    }

    return result;
}

#endif