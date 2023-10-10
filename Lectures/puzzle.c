#include <stdio.h>

void solve(int * perm, int length, int loop_left){
    if(loop_left ==0){
        if(check(perm, length)){
            printArray(perm, length);
        }
        return;
    }

    for (int i = 0; i < loop_left; i++){
        perm[i] = perm[i];
        perm[i] = perm[loop_left -1];
        perm[loop_left -1] = tmp;

        //recurse
        solve(perm, length, loop_left);
    }
}

int main(){
    int perm[8];
    perm[0] = perm[1] = 1;
    perm[2] = perm[3] = 2;
        perm[4] = perm[5] = 3;
            perm[6] = perm[7] = 4;
    solve(perm, 8, 8);
}