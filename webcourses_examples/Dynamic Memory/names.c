
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function to create a dynamic string from some given string
char * createString(char * input) 
{
    // Uses local memory opposed to dynamic
    // char result[10];

    // Create a pointer that will hold the string
    char * result;

    // Dynamically allocate the memory for the string
    result = (char *) malloc((strlen(input) + 1) * sizeof(char));

    // Copy the contents of the input string into the created string
    strcpy(result, input);

    // Return the resulting string
    return result;
}

// the main function
int main() 
{
    // char *** (3D array of characters)
    // Create the array of strings
    char ** names = (char **) malloc(5 * sizeof(char *));

    // names (char **)
    // names[#] (char *)
    // Create all the individuals names in the names array
    names[0] = createString("Alice");
    names[1] = createString("Bob");
    names[2] = createString("Carol");
    names[3] = createString("Dean");
    names[4] = createString("Eric");

    // Loop through the names and print them out
    for (int i = 0; i < 5; i++)
    {
        printf("names[%d] = \"%s\"\n", i, names[i]);
    }

    // Clean up all the memory
    for (int i = 0; i < 5; i++)
    {
        free(names[i]);
    }
    
    // Free the 2D array of charactes
    free(names);

    // Exit the program
    return 0;
}
