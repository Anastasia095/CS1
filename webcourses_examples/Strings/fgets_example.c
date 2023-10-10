// This program demonstrates how to read in a line of text from the 
// user using the fgets function

// Include some common libraries
#include <stdio.h>
#include <stdlib.h>

// The main function
int main() 
{
    // Read in up to 100 charaters*
    char str[100];
    fgets(str, 100, stdin);

    // Loop to the end of the string
    for (int i = 0; str[i] != '\0'; i++) 
    {
        // Check which type of character we have encountered
        if (str[i] == ' ') 
        {
            printf("<space>\n");
        }
        else if (str[i] == '\n') 
        {
            printf("<newline>\n");
        }
        else
        {
            printf("'%c'\n", str[i]);
        }
    }

    // Exit the program
    return 0;
}

// * technically we cannot read in a full 100 characters because fgets
//   naturally will write a null terminator at the end but still inside 
//   the specified buffer length.
//   Additionally fgets will also try to store the newline character, so
//   this is really ~like~ reading in 98 characters.
//   For example, typing in 99 characters and then a newline would allow
//   fgets to read in a full 99 characters, but the newline would be in
//   the buffer still.
//   Conversely, typing 98 characters and then a newline would allow fgets
//   to read in all 98 characters AND the newline.
