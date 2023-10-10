
// This program desmonstrates the strcpy and strcmp functions

// Include the string header file containing the string functions
#include <string.h>

// Include the input output header file containing stuff for printing
#include <stdio.h>

// The main function
int main() 
{
    // Store "James" into first name
    char first_name[5 + 1];
   
    // Tries to change the address that first_name points to
    // first_name = "James";
    strcpy(first_name, "James"); // first = second;

    // Print the string before change
    printf("Before name change: %s\n", first_name);

    // Change "James" to "Jim"
    first_name[1] = 'i';
    first_name[3] = '\0'; // 0 is value of '\0'

    // Print the name after the change
    printf("After name change: %s\n", first_name);

    // Create a second name
    char second_name[5 + 1];
    strcpy(second_name, "jim");

    // "Jim" vs "jim"
    printf("%d\n", strcmp(first_name, second_name));

    // Exit the program
    return 0;
}
