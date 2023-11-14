
// This program sorts an array of values using the quick sort

// Include useful header files
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// A custom array type
typedef int ArrayType;

// Default size of the array
#define DEFAULT_N 10

// The prototypes of the functions used
void gen_array(int * arr, int n);
void quick_sort_array(int * arr, int n);
void print_array(int * arr, int n);
void check_sorted_array(int * arr, int n);

// A function to generate an array of values
void gen_array(int * arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 101;
}

// Function to swap 2 values using the reference
void swap(ArrayType * a, ArrayType * b) { // Change these types
    ArrayType tmp = *a; // change this type
    *a = *b;
    *b = tmp;
}

// Function that returns 1 if a < b
// returns 0 otherwise
int less_than(ArrayType a, ArrayType b) {
    return (a < b);
}

//      pivot   |   < pivot   |  < pivot  |   >= pivot  |   >= pivot  |
//                                 bPtr         fptr
// This quick sort is not good on arrays with duplicate values.
// The quick sort is O(Nlog(N)) in both best and average case.
// The quick sort is O(N^2)
void quick_sort_array(ArrayType * arr, int n) { // change this type
    if (n <= 1) {
        return; // already sorted :)
    }
    ArrayType pivotValue = arr[0]; // change this type
    int fPtr = 1;
    int bPtr = n - 1;
    
    // Determine into which side each value will go
    for (int i = 0; i < n-1; i++) {
        if (less_than(pivotValue, arr[fPtr])) { // Update this comparison
            // TOO BIG
            // Move to back
            swap(arr + fPtr, arr + bPtr);
            
            // Update the bPtr
            bPtr--;
        } else {
            // SMALL ENOUGHT
            // Leave the value in the spot (do nothing)
            // Update the front pointer
            fPtr++;
        }
    }
    
    // Move the pivot into the correct location
    swap(arr + 0, arr + bPtr);

    // Sort recursively
    quick_sort_array(arr, bPtr);
    quick_sort_array(arr + bPtr + 1, n - (bPtr + 1)); 
}

// Print the values separated by spaces
void print_array(int * arr, int n) {
    for (int i = 0; i < n; i++) { 
        printf("%d", arr[i]);
        if (i == n-1) printf("\n");
        else printf(" ");
    }
}

// Function t check if an array is sorted
void check_sorted_array(int * arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        assert(arr[i] <= arr[i + 1]);
    }
}

#define TOO_BIG 500

// The main function
int main(int argc, char ** argv) {
    int n = DEFAULT_N;
    
    // Use arguments to customize the value of n
    if (argc > 1) n = atoi(argv[1]);
    
    // Allocate the arrayZ
    ArrayType * arr = (ArrayType *) malloc(sizeof(ArrayType) * n);
    gen_array(arr, n);
    
    // Print the original array if it is not too big
    if (n < TOO_BIG)
        print_array(arr, n);
    	
    // Sort the array
    quick_sort_array(arr, n);
    
    // Print the sorted array if it is not too big
    if (n < TOO_BIG)
        print_array(arr, n);
    	
    // Use a function to check the array is sorted
    check_sorted_array(arr, n);
 
    // Free the array of 
    free(arr);

    // Exit the program
    return 0;
}
