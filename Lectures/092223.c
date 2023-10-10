#include <stdio.h>
#include <stdlib.h>

//read into an array n values
//INput: the array (pointer)

void rec_read(int * arr, int n) {
    if (n != 0) {
        //Read into the last position of the array
        scanf("%d", arr[n - 1]);

        rec_read(arr, n -1);
    }
}

//Print the array to screan
//Input: the array (pointer)
// the size of the array

void rec_print(int * arr, int n){
    if (n != 0){
        printf("%d", arr[0]);
        rec_print(arr +1, n -1);
    } else {
        //BASE CASE: TERMINATE LINE
    }
}


int main(){

//Exit
    return 0;
}