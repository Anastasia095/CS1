
// This program demonstrates reading an array of integers
// recursively

#include <stdio.h>
#include <stdlib.h>

// Read into an array n values
// Input: the array (pointer)
//        the size of the array
void rec_read(int * arr, int n) 
{
    // Check if we need to read at least one value
    if (n != 0) 
    {
        // Read in an array of size n - 1 recursively
        rec_read(arr, n - 1);
        
        // Read into the last position of the array
        scanf("%d", &arr[n - 1]);
    }
}

// Print the array to screen
// Input: the array (pointer)
//        the size of the array
void rec_print(int * arr, int n) 
{
    // Check if there is at least 1 value
    if (n != 0) 
    {
        // Print the first value of the array
        printf("%d ", arr[0]);

        // Print the remaining value afterwards
        rec_print(arr + 1, n - 1);
    } 
    else 
    {
        // BASE CASE: Terminate line
        printf("\n");
    }
}

// The main function
int main() 
{
    // Read in the number of numbers to read
    int n;
    scanf("%d", &n);
    
    // Create the array of integers to read
    int * arr = (int *) malloc(sizeof(int) * n);

    // Recursively read
    rec_read(arr, n);

    // Print the array
    rec_print(arr, n);

    // Free memory
    free(arr);

    // Exit
    return 0;
}
