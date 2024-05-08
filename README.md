# Efficient Matrix Traversal: Dynammic Backtracking Algorithm 
### Authors:
## Vu Le [![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-blue)](https://www.linkedin.com/in/vu-le-255601192) | Taher Ali [![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-blue)](https://www.linkedin.com/in/taherali181) | Dylan Skroskznik [![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-blue)](https://www.linkedin.com/in/dylan-skroskznik) 

---
## Overview
In Optimal Matrix Traversal, we as a group developed a program that implemented a dynamic programming algorithm for efficiently computing the minimum distance and optimal path from any cell in the bottom row of a matrix to the top row. We than demonstrate an alternative direction for iterative construction of this optimal matrix traversal algorithm by traversing the matrix from bottom row to top row. We utilized memoization techniques, iterative and recursive practice for dynammic programming, and implement backtracking standards for our algorithms to demonstrate this program outputs an optimal outcome.

## Contents
- [Clone And Run](#clone-and-run)
- [Documentation](#documentation)
- [Analysis](#analysis)
- [License](#license)

## Clone And Run
1. **Clone repository & add to directory of preference**
2. **Compile the program in the terminal or any code editor**\
    a.  Use commands ```make``` depending on operating systems (I used ```mingw32-make.exe``` to run make files)\
    b.  An alternative to run the program files are g++ command syntax
```cpp
   g++ -Wall -Wextra -std=c++20 main.cpp -o traverse
```   
3. **Run the Program executable/output files in current directory**
   ```./traverse``` 'OR' ```./{name_here}```
4. **Check Output in text file in current directory**
   ```traversal-output.txt```

## Documentation
Navigate to this link to the PDF for the Project Documentation for this Optimized Matrix Traversal group exercise
  - [Optimal-Matrix-Traversel-Project-Overview-Documentation.pdf](Optimal-Matrix-Traversel-Project-Overview-Documentation.pdf)

## Analysis
1. **Prefacing the Problem with Base Case**
   - To start breaking down the calculation of the minimum distance from a cell on the bottom row to the top row, divide this into subproblems that find the minimum distance from any cell in our matrix to the top row. Doing this allows us to reuse previous results rather than computing these subproblems for each cell every time it is encountered.
   - Let's only compute the minimum distance to a cell once. When computing the minimum distance for any cell in our matrix (except cells in the top row), the minimum distance can be broken down into the cost of all previous steps plus the minimum cost of traversing to our current cell.
   - A base case to prefacing this sub solution to travering the matrix, recurrence is when i = 0. The top row is our starting point, so we can just store the distance of traversing that top cell whenever it is encountered.
   - ```D(i,j)``` function to create 2d matrix with parameters i, j 
   - In the otherwise case, if j is out of bounds (j > column.size or j < 0), then that subproblem
will not be considered in our minimum calculation.
```python
    D(i,j) = array[i,j]                 # if i = 0
    D(i,j) =                            # Otherwise...
        min(D(i-1,j) + array[i,j],     
        D(i-1,j-1)+ array[i,j] * 1.4,
        D(i-1,j+1) + array[i,j] * 1.4 
```

2. **Memoizing Algorithm from Base Case examined for Minimum Matrix Traversal**
   - Since we now examined this base case to expand to constructing a memoization of the minimum matrix traversal algorithm through allow parameters and wrapper functions for the memoized functions from this base case algorithm.
   - For memoizing this algorithm, we must compute the minimum path to each cell once. We can assume that each cell in our array stores the minimum distance to each matrix cell,the directions that were taken, and the starting column of that path dependent on the positionings. Here is how we can write the memoized algorithm as a recursion.
```python
# Input: i x j matrix with traversal values for each cell
# Output: MinTraversal to each column in bottom row of matrix
Algorithm: MinPathWrapper(i,j)
    array = Array(i, j)
    Initialize 'array' to -1
    Let x = index of bottom row
    For every column y in matrix:
        MinPathMemo(x, y, array)
 
Algorithm: MinPathMemo(i, j)
    if array[i][j] = -1
        if i = 0 then
            array[i][j] = array[i][j]
        else
            array[i][j] = min(D(i-1,j) + array[i,j],
                          D(i-1,j-1)+ array[i,j] * 1.4,
                          D(i-1,j+1) + array[i,j] * 1.4)
    return array[i][j]
```
3. **Renewed Solution for Optimal Matrix Traversal with Iterative Dynamming Algorithm**
   - By using this base case and performing iterative practice through the matrix, we can demonstrate this matrix traversal with dynammic programming practices and iterating will allow for multiple computation of each cell by knowing our matrix dimensions.
   - An iterative dynammic algorithm to this optimal matrix traversal in bruteforcing in storing the optimal route from starting at the bottom of the matrix, working backwards and storing weighted traversal value until reaching the top of the matrix (dependent on the dimensions)
```python
# Input: n: rows, m: col
# Input: matrix D, sizes of rows n and col m
# Output: traversed matrix T, cost of min traversal, traversal directions of min distance
Algorithm: 2Dmatrixtraversal

    Store given matrix values in array[n][m]
    Initialize top row of matrix to traversal value 
    path = array to store variables for distance traversed, start column for each cell traversed, and directions taken
    for i to n do
        for j to m do
            if i = 0 then
                path[i][j].distance = matrix[i][j]
                path[i][j].startColumn = j
            else
                min = paths[i-1][j].distance + matrix[i][j]
                dir = 0 (0: S, 1: SW, 2: SE)
 
                if traversing southwest is cheapest then
                    min = paths[i-1][j+1].distance + matrix[i][j] * 1.4
                    dir = 1
                    Update path directions = SW
                    Update startColumn = paths[i-1][j+1].startColumn
                end
                if traversing southeast is cheapest
                    min = paths[i-1][j-1].distance + matrix[i][j] * 1.4
                    dir = 2
                    Update path directions = SE
                    Update startColumn = paths[i-1][j-1].startColumn
                end
                if traversing south is cheapest
                    paths[i][j].directions = paths[i-1][j].directions
                    Update path directions = S
                    Update startColumn = paths[i-1][j].startColumn
                end
                    Update paths[i][j].distance to min
            end
        end
    return path
```
   
4. **Additonal Memoizing the Iterative Solution**
    - Furthermore, we can employ memoization strategy towards this solution that works similar to the previous by computing the shortest path by column on top row when iterating from bottom row to top row. Each cell in the matrix is storing traversal length of the matrix cells visited plus directions taken previously.
    - The algorithms wrapper function is slightly different to the previous, along with the memoized case in which it's applying matrix size first and is tracing and iterating thoroughly towards the end of the matrix at the top row to locate the minimum path to take for optimal matrix traversal.
```python
# Input: i x j matrix with traversal values for each cell
# Input: column m in top row of matrix
# Output: MinTraversal to column m in the top row
Algorithm: MinPathWrapper(i,j)
    array = Array(i, j)
    Initialize 'array' to-1
    MinPathMemo(0, m, array)

Algorithm: MinPathMemo(i, j)
    if array[i][j] =-1
        if (i = array.size()-1) then
            array[i][j] = array[i][j]
        else
            array[i][j] = min(D(i+1,j) + array[i,j],
                          D(i+1,j-1)+ array[i,j] * 1.4,
                          D(i+1,j+1) + array[i,j] * 1.4)
    return array[i][j]
```

5. **Determining The Complexity for Optimal Matrix Traversal**
    - So, the overall complexity of our memoized algorithm is ```O(i * j)``` where ```i``` is the number of rows and ```j``` is the number of columns. Let's explain this further.
    - The memoized algorithms have a time complexity of ```O(i * j)```, where ```i``` is the number of rows and j is the number of columns in the matrix. This complexity arises due to the initialization of the 2D matrix and the computation of the minimum path for each cell only once.
   -  These wrapper functions are a time complexity of ```O(i * j)``` as stated initialization and setting all values to -1 both take ```O(i * j)``` which dominates the complexity.The memoized function will only compute a value at ```[i,j]``` once, so the minimum path for every cell in our 2D Matrix is only calculated once.



## Licensing
This project is licensed under the Standard Apache License - see the [LICENSE.md](LICENSE.md) file for details.

