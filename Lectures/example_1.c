#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CAP 4

typedef struct student student;
typedef struct list list;

struct student {
    char * name;
    int grade;
};

struct list {
    student * array;
    int size;
    int cap;
};

//createList
list * createList() {
    list * result;
    result = (list *) malloc(sizeof(list));
    result->array = (student *) malloc(sizeof(student) * DEFAULT_CAP); //TODO
    result->size = 0;
    result->cap = 4;
}
// append
void append(list * my_list, char * name, int grade){
    if (my_list->size == my_list->cap){
        //expendd the list
        my_list->array = (student *) realloc(my_list->array, 2 * my_list->cap * sizeof(student));
        my_list->cap *= 2;
    }
}

//put value in the correct location (size)
my_list->array[my_list->size].grade = grade;
my_list->array[my_list->size].name = strdup(name);
my_list->size++;

//Update the size of the list
//deleteList

int main(){
    list * my_list;
    my_list = createList();

    append(my_list, "Alice", 100);
    append(my_list, "Jeff", 99);
    append(my_list, "Travis", 65);
    append(my_list, "Doug", 90);
    append(my_list, "Rodric", 30);
    append(my_list, "James", 15);
    append(my_list, "Jane", 45);
    append(my_list, "Gym", 30);



    deleteList(my_list);
}



