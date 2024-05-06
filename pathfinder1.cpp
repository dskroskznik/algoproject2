#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Cell{          // DS for each cell, we can store distance from current cell to the top, as well as previous directions we've computed, and where we started
    double distance;
    vector<string> directions;
    int startColumn;
};

vector <vector<Cell> > calcPaths(vector<vector<double> > &matrix, int rows, int cols){
    vector<vector<Cell> > paths(rows, vector<Cell>(cols));

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (i == 0){                // Base Case: top row, just store the distance of traversing that cell and start column.
                paths[0][j].distance  = matrix[0][j];
                paths[0][j].startColumn = j;
            }
            else{
                double down = paths[i-1][j].distance + matrix[i][j]; // assume that going south is cheapest at first, since going SE or SW has 40% penalty
                double min = down;
                int dir = 0; // 0 = south, 1 = southwest, 2 = southeast 
                
                if (min > paths[i-1][j+1].distance + matrix[i][j] * 1.4 && j < cols - 1){       // check if going southwest is cheapest
                    min = paths[i-1][j+1].distance + matrix[i][j] * 1.4;
                    dir = 1;
                    paths[i][j].directions = paths[i-1][j+1].directions;                        // update directions and start column
                    paths[i][j].directions.push_back("SW");
                    paths[i][j].startColumn = paths[i-1][j+1].startColumn;
                }
                if (min > paths[i-1][j-1].distance + matrix[i][j] * 1.4 && j > 0){              // check if going southeast is cheapest
                    min = paths[i-1][j-1].distance + matrix[i][j] * 1.4;
                    dir = 2;
                    paths[i][j].directions = paths[i-1][j-1].directions;                        // update directions and start column
                    paths[i][j].directions.push_back("SE");
                    paths[i][j].startColumn = paths[i-1][j-1].startColumn;
                }
                if (dir == 0){
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

int main(){

    ifstream inputFile("input-small.txt");               // open input file
    if (!inputFile){
        cerr << "Error opening file.\n";
        exit(1);
    }

    int r, c;
    inputFile >> r >> c;

    vector<vector<double> > matrix(r, vector<double>(c));
    for (int i = 0; i < r; i++){         // store input cells into matrix
        for (int j = 0; j < c; j++){
            inputFile >> matrix[i][j];
        }
    }
    inputFile.close();


    vector <vector<Cell> > paths = calcPaths(matrix, matrix.size(), matrix[0].size());
    ofstream output("output.txt");
                                                        // iterate through bottom row of paths matrix and output distance, start column, 
                                                        // and directions to output txt
    int bottomRow = paths.size() - 1;              
    for (int col = 0; col < paths[bottomRow].size(); col++){
        output << paths[bottomRow][col].distance << " " <<paths[bottomRow][col].startColumn << " ";
        for (int dir = 0; dir < paths[bottomRow][col].directions.size(); dir++){
            output << paths[bottomRow][col].directions[dir] << " ";
        }
        output << endl;
    }
    output.close();
    return 0;
}