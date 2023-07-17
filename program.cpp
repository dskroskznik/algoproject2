#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#define SENT 1

using namespace std;
/*
void traverse_cost(long int row, long int col, long int (**mat), long double (**arr)) 
{
    long int i, j;
    long double S, SW, SE = 0;

    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) 
        {
            if(j == 0) {
                S = arr[i + 1][j];
                SE = arr[i + 1][j + 1] * 1.40;
                int minDistance1 = min(SE, S);
                arr[i][j] = minDistance1 + mat[i][j];
            } 
            else if(j == col-1) {
                S = arr[i + 1][j];
                SW = arr[i + 1][j - 1] * 1.40;
                int minDistance2 = min(S, SW);   
                arr[i][j] = minDistance2 + mat[i][j];
            }
            else {
                S = arr[i + 1][j];
                SE = arr[i + 1][j + 1] * 1.40;
                SW = arr[i + 1][j - 1] * 1.40;
                int minDistance3 = min(S, SW, SE);
                arr[i][j] = minDistance3 + mat[i][j];
            }
        }
    }
}
*/

int main(int argc, char *argv[]) 
{
    long int ROW, COL, i, j;
    long double S, SW, SE = 0;
    cin >> ROW;
    cin >> COL;
    long int **matrix;
    long double **distance;

    //initialize matrix
    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            matrix[i][j] = i * 2 + 1;
            distance[i][j] = matrix[i][j];
        }
    }

    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            distance[0][j] = 1 + j;
        }
    }

    //traverse_cost(ROW,COL,matrix,distance);


    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) 
        {
            if(j == 0) {
                S = distance[i + 1][j];
                SE = distance[i + 1][j + 1] * 1.40;
                int minDistance1 = min(SE, S);
                distance[i][j] = minDistance1 + matrix[i][j];
            } 
            else if(j == COL-1) {
                S = distance[i + 1][j];
                SW = distance[i + 1][j - 1] * 1.40;
                int minDistance2 = min(S, SW);   
                distance[i][j] = minDistance2 + matrix[i][j];
            }
            else {
                S = distance[i + 1][j];
                SE = distance[i + 1][j + 1] * 1.40;
                SW = distance[i + 1][j - 1] * 1.40;
                int minDistance3 = min(S, SW, SE);
                distance[i][j] = minDistance3 + matrix[i][j];
            }
        }
    }

    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            cout << "\'" << distance[i][j] << "\' " << "\t";
        }
        cout << "\n";
    }
/*
    // printing matrix
    cout << "[" ;
    for(i=0; i<ROW; i++) {    
        for(j=0; j<COL; j++) {
            if(matrix[ROW-1][COL-1] == matrix[i][j]) {
                cout << "\'" << matrix[i][j] << "\'] " << "\t";
            }
            else {
                cout << "\'" << matrix[i][j] << "\', " << "\t";
            }
        }
        if(matrix[i][j] == matrix[COL-1][ROW-1]) {
            cout << "\']";
        }
        cout << "\n";
    }*/
    cout << "\n";
    return 0;
}