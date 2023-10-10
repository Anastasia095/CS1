
// This program makes and uses its own version of a string length function

// Include the standard input and output header
#include <stdio.h>

// Include the string header with strlen to compare against our own 
// length function
#include <string.h>

// Our version of the string length function
int myLen(char * string) 
{
    // Start at the first position in the string
    int index = 0;

    // Loop while the character at the index is non-zero
    while (string[index])
        index++; // Increment index
                 
    // The index is now at the null terminator
    return index;
}

// The main function
int main() 
{
    // The string
    char * str = "Independence Day";

    // Check the length of the string using our string length
    printf("%s has %d characters.\n", str, myLen(str));

    // Check the length of the string using the string.h's length function
    printf("%s has %zd characters.\n", str, strlen(str));

    // Exit the program successfully
    return 0;
}
