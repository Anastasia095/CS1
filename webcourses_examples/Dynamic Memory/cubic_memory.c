
// This program shows how to make a 3D array in C dynamically

#include <stdio.h>
#include <stdlib.h>

// The main function
int main() 
{
    // The pointer to the 3D array
    int *** cube;

    // Create the first dimension
    cube = (int ***) malloc(10 * sizeof(int **));
    
    // We need to create a grid for each part of the first dimension
    for (int i = 0; i < 10; i++) 
    {
        // Create a 2D array for this part of the 3D array
        cube[i] = (int **) malloc(10 * sizeof(int *));

        // We need to create a row for each pair of the first 2 dimensions
        for (int j = 0; j < 10; j++) 
        {
            // Create a row dynamically
            cube[i][j] = (int *) malloc(10 * sizeof(int));
        }
    }

    // Free all the memory in reverse allocation order
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 10; j++) 
        {
            free(cube[i][j]);
        }
        free(cube[i]);
    }
    free(cube);

    // Exit the program
    return 0;
}
