#include <iostream>
#include "matrixcell.hpp"
#include "pathfinder.hpp"

using namespace std;

vector<vector<Cell>> calculatePath(vector<vector<double> > &matrix, int rows, int cols)
{ 
    vector<vector<Cell>> paths(rows, vector<Cell>(cols));
    int i, j;

    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < cols; j++) 
        {
            if (i == 0) {                // Base Case: top row, just store the distance of traversing that cell and start column.
                paths[0][j].distance  = matrix[0][j];
                paths[0][j].startColumn = j;
            }
            else 
            {
                double down = paths[i-1][j].distance + matrix[i][j]; // assume that going south is cheapest at first, since going SE or SW has 40% penalty
                double min = down;
                int dir = 0; // 0 = south, 1 = southwest, 2 = southeast 
                
                if (min > paths[i-1][j+1].distance + matrix[i][j] * 1.4 && j < cols - 1) {       // check if going southwest is cheapest
                    min = paths[i-1][j+1].distance + matrix[i][j] * 1.4;
                    dir = 1;
                    paths[i][j].directions = paths[i-1][j+1].directions;                        // update directions and start column
                    paths[i][j].directions.push_back("SW");
                    paths[i][j].startColumn = paths[i-1][j+1].startColumn;
                }
                if (min > paths[i-1][j-1].distance + matrix[i][j] * 1.4 && j > 0) {              // check if going southeast is cheapest
                    min = paths[i-1][j-1].distance + matrix[i][j] * 1.4;
                    dir = 2;
                    paths[i][j].directions = paths[i-1][j-1].directions;                        // update directions and start column
                    paths[i][j].directions.push_back("SE");
                    paths[i][j].startColumn = paths[i-1][j-1].startColumn;
                }
                if (dir == 0) {
                    paths[i][j].directions = paths[i-1][j].directions;                           // if going south was cheapest
                    paths[i][j].directions.push_back("S");
                    paths[i][j].startColumn = paths[i-1][j].startColumn;           
                }
                paths[i][j].distance = min;
            }
        }
    }
    return paths;
}
