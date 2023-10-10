// This program demonstrates how to iterate through
// Many possible passwords

// The header file for printing
#include <stdio.h>

// The brute force function that stores how many remaining
// loops are required
void crack(int length, int loops_left, char * pass) {
    // BASE CASE: there are no more loops left
    if (loops_left == 0) {
        // Try pass
        printf("pass: %s\n", pass);

        // Exit
        return;
    }

    // RECURSIVE CASE: Try all possibilities for the letter
    for (char c = 'a'; c <= 'z'; c++) {
        // 1-indexed loops_left to 0-indexed array
        pass[loops_left - 1] = c;

        // Recursively brute force
        crack(length, loops_left - 1, pass);
    }
    
    // RECURSIVE CASE: Try all upper case letters
    for (char c = 'A'; c <= 'Z'; c++) {
        // 1-indexed loops_left to 0-indexed array
        pass[loops_left - 1] = c;

        // Recursively brute force
        crack(length, loops_left - 1, pass);
    }
}

// The main function
int main() {
    // Creating a password string
    char pass[5];
    pass[4] = 0;

    // Recursively crack the password
    crack(4, 4, pass);

    // Exit the program
    return 0;
}
