#include <iostream>
#include "pathfinder.cpp"

int main() 
{
    unsigned int r, c, i, j, k, m;

    // Change text filename here 
//  ifstream file("input-small.txt");
    ifstream file("input-tiny.txt");
    if (!file){
        cerr << "There was an error opening the text file.\n";
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
    ofstream output("traversal-output.txt");
    // iterate through bottom row of paths matrix and output distance, start column, 
    // and directions to output txt
    int bottomRow = paths.size() - 1;         
    for (k = 0; k < paths[bottomRow].size(); k++){
        output << paths[bottomRow][i].distance << " " <<paths[bottomRow][i].startColumn << " ";
        for (m = 0; m < paths[bottomRow][i].directions.size(); m++){
            output << paths[bottomRow][i].directions[k] << " ";
        }
        output << endl;
    }
    output.close();
    return 0;
}