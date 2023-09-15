#include <iostream>
#include "pathfinder.cpp"

int main() 
{
    unsigned int r, c, i, j, dir;

    ifstream file("input.txt");               // open input file
    if (!file){
        cerr << "Error opening file.\n";
        exit(1);
    }

    file >> r >> c;

    vector<vector<double>> matrix(r, vector<double>(c));
    for (i = 0; i < r; i++){         // store input cells into matrix
        for (j = 0; j < c; j++){
            file >> matrix[i][j];
        }
    }
    file.close();

    vector<vector<Cell>> paths = calculatePath(matrix, matrix.size(), matrix[0].size());
    ofstream output("output.txt");
                                                        // iterate through bottom row of paths matrix and output distance, start column, 
                                                        // and directions to output txt
    int bottomRow = paths.size() - 1;         
    for (i = 0; i < paths[bottomRow].size(); i++){
        output << paths[bottomRow][i].distance << " " <<paths[bottomRow][i].startColumn << " ";
        for (dir = 0; dir < paths[bottomRow][i].directions.size(); dir++){
            output << paths[bottomRow][i].directions[dir] << " ";
        }
        output << endl;
    }
    output.close();
    return 0;
}