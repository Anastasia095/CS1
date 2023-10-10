
// A recursive program to solve a permutation puzzle given in
// class.
// Find all permutations of 1,1, 2,2, 3,3, 4,4, ... n,n
// Such that each pair of identical values is separated by
// a distance based on the value
// Solution for n=4
//      4, 1, 1, 3, 4, 2, 3, 2

// Input Output header
#include <stdio.h>

// Function to check if a given permutation is valid
int check(int * perm, int n) 
{
    // Loop through all the values
    for (int cur = 0; cur < n; cur++) 
    {
        // Delare a variable to old another index
        int other;

        // Check foward
        other = cur + perm[cur];
    
        // Check if the forward location has the same value
        if (other < n && perm[other] == perm[cur])
            continue;

        // Check backward
        other = cur - perm[cur];

        // Check if the backward location has the same value
        if (other >= 0 && perm[other] == perm[cur])
            continue;

        // The permutation was invalid
        return 0;
    }

    // No invalid values found
    return 1;
}

// Function to print an array with a given size
void printArray(int * arr, int n) 
{
    // Loop through and print the array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Print a end of line character
    printf("\n");
}   

// Recursive function to solve the puzzle.
// Values are fixed starting at the higher indices and going to
// lower indices.
// The values in the prefix are values that have not had their
// location determined yet.
void solve(int * perm, int length, int loop_left) 
{
    // Check if we should no longer loop
    if (loop_left == 0) 
    {
        // Check if the solution is valid
        if (check(perm, length)) 
        {
            // Print the valid solution
            printArray(perm, length);
        }
        
        // Exit the function
        return;
    }

    // Loop through all the values that have not been fixed 
    // yet
    for (int i = 0; i < loop_left; i++) 
    {
        // fill in spot at loop_left - 1
        int tmp = perm[i];
        perm[i] = perm[loop_left - 1];
        perm[loop_left - 1] = tmp;

        // Recurse
        solve(perm, length, loop_left - 1);
        
        // Undo the swap made to form the permutation
        tmp = perm[i];
        perm[i] = perm[loop_left - 1];
        perm[loop_left - 1] = tmp;
    }
}

// The main function
int main() 
{
    // Create initial puzzle state
    int perm[8];
    perm[0] = perm[1] = 1;
    perm[2] = perm[3] = 2;
    perm[4] = perm[5] = 3;
    perm[6] = perm[7] = 4;

    // Solve recursively
    solve(perm, 8, 8);
    
    // Exit the program
    return 0;
}
