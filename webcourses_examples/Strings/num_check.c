
// This program checks if a string is a number by looking at the characters
// This program also tests using atoi to convert a string to a number

// Include the input output header
#include <stdio.h>

// Include the standard library header
#include <stdlib.h>

// Function to check if a string contains only digits '0' - '9'
//  * Returns 1 if all digits
//  * Returns 0 if there are at least 1 non-digit character
int isNum(char * str) 
{
    // Loop through the characters of the input string
    for (int i = 0; str[i] != '\0'; i++) 
    {
        // Check if the character is not a digit
        if (str[i] > '9' || str[i] < '0') 
        {
            return 0;
        }
    }

    // The string had no non-digits, so return 1
    return 1;
}

// The main function
int main() 
{
    // Create 2 strings that are like numbers
    char * str_1 = "8675309";
    char * str_2 = "6ix9ine";
    
    // Check the first string
    if (isNum(str_1)) 
    {
        printf("%s is a number.\n", str_1);

        // Convert the string into a number using atoi
        int x = atoi(str_1);
        printf("%s - 1 is %d.\n", str_1, x - 1);
    } 
    else 
    {
        printf("%s is not a number.\n", str_1);
    }

    // Check the second string
    if (isNum(str_2)) 
    {
        printf("%s is a number.\n", str_2);

        // Convert the second string into a number
        int x = atoi(str_2);
        printf("%s - 1 is %d.\n", str_2, x - 1);
    }
    else
    {
        printf("%s is not a number.\n", str_2);
    }

    // Exit the program
    return 0;
}
