#include <iostream>
#include <fstream>
#include <vector>
#include "pathfinder.cpp"

int main() 
{
    //ifstream file("input-tiny.txt");
    ifstream file("input-small.txt");
    if (!file)
    {
        cerr << "There was an error opening the text file.\n";
        exit(1);
    }

    unsigned int i, j, k, m;
    unsigned int c, r;
    file >> r >> c;

    vector<vector<double>> matrix(r, vector<double>(c));

    for (i=0;i<r;i++)
    {         
        // Store the input file cells into matrix
        for (j=0;j<c;j++)
        {
            file >> matrix[i][j];
        }
    }
    file.close();

    vector<vector<Cell>> paths = calculatePath(matrix, matrix.size(), matrix[0].size());
    ofstream output("traversal-output.txt");
    // iterate through bottom row of paths matrix and output distance, 
    // start column, and directions to output txt
    int bottomRow = paths.size() - 1;         
    for (k=0;k<paths[bottomRow].size();k++)
    {
        output << paths[bottomRow][k].distance << " " << paths[bottomRow][k].startColumn << " ";
    
        for (m=0;m<paths[bottomRow][m].directions.size();m++)
        {
            output << paths[bottomRow][k].directions[m] << " ";
        }

        output << endl;
    }
    output.close();
    return 0;
}