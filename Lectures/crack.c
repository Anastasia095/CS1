#include <stdio.h>

void crack(int length, int loops_left, char * pass){
    //Base Case: there are no more loops left
    if(loops_left == 0){
        printf("pass: %s\n", pass);

        //exit
        return;
    }

    //recursive case: try all posibilities for letter
    for(char c = 'a'; c <= 'z'; c++){
        //1-indexed loops_left to 0-indexed array
        pass[loops_left - 1] = c;

        //recursively brute force
        crack(length, loops_left-1, pass);
    }
        //recursive case: try all posibilities for letter
    for(char c = 'A'; c <= 'Z'; c++){
        //1-indexed loops_left to 0-indexed array
        pass[loops_left - 1] = c;

        //recursively brute force
        crack(length, loops_left-1, pass);
    }
}

int main(){
    //creating a password string
    char pass[5];
    pass[4] = 0;

//recursively crack the password
    crack(4, 4, pass);

    return 0;
}