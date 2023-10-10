
// This program demonstrates how to remove in a list by a 
// given index

// Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Starting size of the array list
#define DEFAULT_CAP 4

// The aliases 
typedef struct student student;
typedef struct list list;

// The struct definitions
struct student 
{
    char * name;
    int grade;
};
struct list 
{
    student * array;
    int size;
    int cap;
};

// Function to create a list
list * createList()
{
    // Declare
    list * result;

    // Allocate
    result = (list *) malloc(sizeof(list));
    
    // Initialize
    result->array = (student *) malloc(sizeof(student) * DEFAULT_CAP);
    result->size = 0;
    result->cap = DEFAULT_CAP;

    // Return the address of the list created dynamically
    return result;
}

// Function to add a student to the end of the list
void append(list * my_list, char * name, int grade) 
{
    // Check if at capacity
    if (my_list->size == my_list->cap) 
    {
        // expand the list
        my_list->array = (student *) realloc(my_list->array,
                                             2*my_list->cap*sizeof(student));
        my_list->cap *= 2;
    }   

    // Put the value in the correct location (size)
    my_list->array[my_list->size].grade = grade;
    my_list->array[my_list->size].name = strdup(name);

    // Update the size of the list
    my_list->size++;
}

// Function to print a given student
void printStudent(student * cur_student) 
{
    printf("%s %d\n", cur_student->name, cur_student->grade);
}

// Function to print a list of students
void printList(list * my_list) 
{
    // Loop through the students in the list
    for (int i = 0; i < my_list->size; i++) 
    {
        // Print the current student 
        // (use point math to get student *)
        printStudent(my_list->array + i);
    }
}

// Function to delete the memory associated with a list
void deleteList(list * my_list) 
{
    // Loop through all the students
    for (int i = 0; i < my_list->size; i++) 
    {
        // Free the name
        free(my_list->array[i].name);
    }
    
    // Free the array
    free(my_list->array);
    
    // Free the list
    free(my_list);
}

// Function to remove a value from a list using its index
// All the remaining values are shifted down to maintain order
void removeByIndex(list * my_list, int index) 
{
    // remove the content at the index
    free(my_list->array[index].name);

    // shift to fill in the empty spot
    for (int i = index; i < my_list->size - 1; i++) 
    {
        my_list->array[i].name = my_list->array[i + 1].name;
        my_list->array[i].grade = my_list->array[i + 1].grade;
    }

    // Check if the list is too small now
    if (my_list->cap != DEFAULT_CAP && 
        my_list->cap >= my_list->size * 4) 
    {
        // Shrink the array
        my_list->cap /= 2;
        my_list->array = 
            (student *) realloc(my_list->array, 
                                sizeof(student) *
                                my_list->cap);
    }

    // Update the size of the list
    my_list->size--;
}

// The main function
int main() 
{
    // Declare the list
    list * my_list;
    
    // Create and initialize the list
    my_list = createList();

    // Add people into the list
    append(my_list, "Alice", 100);
    append(my_list, "Jeff", 99);
    append(my_list, "Travis", 65);
    append(my_list, "Doug",  90);
    append(my_list, "Rodric", 30);
    append(my_list, "James", 96);
    append(my_list, "Jane", 86);
    append(my_list, "Gym", 3);
    append(my_list, "Bobber", 45);
    append(my_list, "Carol", 70);

    // Remove Travis (he ain't no student)
    removeByIndex(my_list, 2);

    // Print the list
    printList(my_list);    

    // Clean up the memory of the list
    deleteList(my_list);

    // Exit the program
    return 0;
}
