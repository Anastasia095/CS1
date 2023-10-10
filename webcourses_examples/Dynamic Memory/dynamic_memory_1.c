
#include <stdio.h>
#include <stdlib.h>


/*
    STACK  too efficient and compressed
    VVVVV
  

    ^^^^
    HEAP
    STATIC

  Dynamic memory (HEAP) use functions to allocate
  Use the pointers (addresses) to those sections to resize and 
    clean up when necessary

  ways to dereference a pointer in c
   1. *
   2. []  
         arr[k]   the same as   *(arr+k)
   3. ->
         struct student * alice;     you cannnot use alice.grade
                                     you must use alice->grade
                                     you can also use (*alice).grade

  malloc, calloc, realloc, free all come from <stdlib.h>

  malloc takes in 1 argument
     - # of bytes in the memory block to create
     - returns a void * to the memory block
     - filled with garbage to begin with
     - Return a NULL pointer if the allocation is a failure
  sizeof "function"
     - take in a data type
     - "return" the number of bytes of that type
     sizeof(int)

  calloc takes in 2 arguments
     - # of items to create, size of each item
     - returns a void * to the memory block
     - fills this allocation with 0-bytes
     - Return a NULL pointer if the allocation is a failure
  */


#define NUM_INTS 1000000

int main(void) {
  int * arr = (int *) (malloc(sizeof(int) * NUM_INTS));

  for (int i = 0; i < NUM_INTS; i++)
    arr[i] = i;

  printf("%d\n", arr[100]);

  free(arr);

  int * arr2 = (int *) (malloc(-1));

  if (arr2 == NULL) {
    printf("Array 2 was not allocated successfully.\n");
  } else {
    // use the array here

    free(arr2);
  }

  // Create an array of 10 integers
  int * arr3 = (int *) (calloc(10, sizeof(int)));


  free(arr3);
  free(arr);
  free(arr2);
  
  
  return 0;
}