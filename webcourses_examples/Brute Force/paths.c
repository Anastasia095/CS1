
// Print all paths from top left to bottom right
// Use only down and right moves

#include <stdio.h>

#include <stdlib.h>

// Recursively try all paths in a grid
// Returns the number of paths to the end
int printPaths(int rows, int cols, int curRow, int curCol, char * path) {

    // BASE CASE: at the end
    if (curRow == rows - 1 && curCol == cols - 1) {
        path[curRow + curCol] = '\0';
        printf("%s\n", path);
        return 1;
    }
    
    // Store the number of paths to the end from this location
    int ans = 0;

    // CASE 1: can go right
    if (curCol != cols - 1) {
        // go right
        // update path
        path[curRow + curCol] = 'R';
        
        // Move right
        ans += printPaths(rows, cols, 
                          curRow, curCol + 1,
                          path);
    }

    // CASE 2: can go down
    if (curRow != rows - 1) {
        // go down
        // update path
        path[curRow + curCol] = 'D';
        
        // Move down
        ans += printPaths(rows, cols, 
                          curRow + 1, curCol,
                          path);
    }

    // Return the computed number of paths from trying both
    // directions
    return ans;
}

// The main function
int main() {
    // The string to hold the path
    char path[100 + 1];

    // Print the paths and the number of paths
    printf("There are %d paths.\n", 
        printPaths(4, 5, 0, 0, path));

    // Exit the program
    return 0;
}
