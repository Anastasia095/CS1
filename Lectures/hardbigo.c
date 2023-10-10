#include <stdio.h>
#include <stdlib.h>

int main() {
    int N = 10000000;

int ans = 0;

    while (N) {
        N = rand() % N; //
        for(int i = 0; i < N; i++){
            ans += rand(); //loop number of times equal to new N
        }
    }

    //AVG
    // T(N) = (1/N)(T(0) + 0 + T(1) + 1 + T(2) +2+ ... + T(N-1) + N - 1)
    //try to apply quick sort to solve this problem

    return 0;
}