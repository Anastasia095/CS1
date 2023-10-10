
// This program demonstrates how to solve a towers of hanoi
// puzzle using recursion

// Header for printing
#include <stdio.h>

// The recursive hanoi solution
// Prints the required number of moves
int hanoi(int n, char * s, char * e, char * a) 
{
    // BASE CASE: No disks in tower
    if (n == 0) 
    {
        // No moves required
        return 0;
    }

    // Store the number of moves required
    int ans = 0;

    // Move all disks on top of this one off (to aux)
    ans += hanoi(n-1, s, a, e);
    
    // Move this largest disk
    printf("Move disk %d from %s to %s\n", n, s, e);
    ans++; // Update the answer 

    // Move all disks back onto the large one (to end)
    ans += hanoi(n-1, a, e, s);

    // Return the reuqired number of moves
    return ans;
}

// The main function
int main() 
{
    // Compute the number of moves and display
    printf("It took %d moves.\n", hanoi(20, "START", "END", "AUX"));

    // Exit the program
    return 0;
}
