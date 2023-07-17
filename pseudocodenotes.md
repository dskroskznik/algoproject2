## Algorithm Notes:
    Input: rows: r, columns: c
    Input: Matrix[r][c]
    Output: T: Traversal cost value, S: Starting position on north border, D: Directions appended string  
    Algo: matrixtraversal

    r = input line argument 1 for rows of matrix
    c = input line argument 2 for col of matrix
    int **matrix
    double **distancematrix

    matrix[r][c] = Initialize with r x c holding sentials -1

    for i to r
        for j to c
            fill matrix[i][j] = file inputs on next line

    for every cell x in northern border
        distancematrix[0][x] = matrix[0][x]

    for i to r-1
        for j to c-1
            if j is 0
                south = distancematrix[i+1][j]
                southeast = distancematrix[i+1][j+1] * 1.40
                minroute = min(south, southeast)
                distancematrix[i][j] = minroute + matrix[i][j]
            else if j is c-1
                south = distancematrix[i+1][j]
                southwest = distancematrix[i+1][j-1] * 1.40
                minroute = min(south, southwest)
                distancematrix[i][j] = minroute + matrix[i][j]
            else
                south = distancematrix[i+1][j]
                southeast = distancematrix[i+1][j+1] * 1.40
                southwest = distancematrix[i+1][j-1] * 1.40
                minroute = min(south, southeast)
                distancematrix[i][j] = minroute + matrix[i][j]


