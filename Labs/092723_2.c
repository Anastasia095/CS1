#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_FRUITS 7
#define BUY_AMOUNT 3

int count;

// Prototype for all recursvive password thing
// Note buy indes and number of Fruit will count down
void comb(char ** fruits, int * current, int curFruit, int buyIndex);

//The main function
int main(){

    int * cur; //Which indices have been selected
    char ** frNames; //The set of fruit names
    int i;

    //Initialize the count to 0
    count = 0;

    //Create memory and initialize memory
    //Maybe do this with input files and loops in the lab
    frNames = (char **) calloc(NUM_FRUITS, sizeof(char *));
    frNames[0] = (char *) calloc(strlen("apples"), sizeof(char));
    strcpy(frNames[0], "apples");
    frNames[1] = (char *) calloc(strlen("grapes"), sizeof(char));
    strcpy(frNames[1], "grapes");
    frNames[2] = (char *) calloc(strlen("oranges"), sizeof(char));
    strcpy(frNames[2], "oranges");
    frNames[3] = (char *) calloc(strlen("grapefruit"), sizeof(char));
    strcpy(frNames[3], "grapefruit");
    frNames[4] = (char *) calloc(strlen("kiwi"), sizeof(char));
    strcpy(frNames[4], "kiwi");
    frNames[5] = (char *) calloc(strlen("tomatoes"), sizeof(char));
    strcpy(frNames[5], "tomatoes");
    frNames[6] = (char *) calloc(strlen("bananas"), sizeof(char));
    strcpy(frNames[6], "bananas");
    cur = (int *) calloc(BUY_AMOUNT, sizeof(int));

    //Fill the arrays
    for (i = 0; i < BUY_AMOUNT; i++){
        cur[i] = -1;
    }

    //Run the recursive methos
    comb(frNames, cur, NUM_FRUITS, BUY_AMOUNT);

    //return a success
    return EXIT_SUCCESS;
}

void comb(char ** fruits, int * current, int curFruit, int buyIndex){
    int i;

    //check if we bought enought fruit
    if(buyIndex == 0){

        //Print and update the count
        printf("%d. ", ++count);

        //Print the stings in the reverse irder ti get the
        //correct order...
        for(i = BUY_AMOUNT -1; i >= 0; i--){

            printf(" %s", fruits[current[i]]);
        }
        printf("\n");

        //Don't do the recursion stuff
        return;
    }
    
    //Check if there is no more fruit to buy
    if (curFruit == 0){

        return; //Not possible to buy fruit
    }

    //------------------Buy the current fruit------------------
    //This line reverse the full print
    // current[buyIndex -1] = curFruit -1;
    // This line makes the print in the cirrect order
    current[buyIndex -1] = NUM_FRUITS - curFruit;

    //Recurse with one less things to buy
    comb(fruits, current, curFruit - 1, buyIndex - 1);

    //------------------Don't the current fruit----------------
    current[buyIndex -1] = -1;

    //Recurse with the same number of things to buy
    comb(fruits, current, curFruit -1, buyIndex);

    //---------------Return-------------------------
    return; // not necessary for this function type
}