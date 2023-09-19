#ifndef MATRIXCELL_HPP
#define MATRIXCELL_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Cell {          // DS for each cell, we can store distance from current cell to the top, as well as previous directions we've computed, and where we started
    vector<string> directions;
    double distance;
    int startColumn;
};

#endif