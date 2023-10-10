//FIN THE VALUE BEST WORST AVERAGE CASES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int N = 20;
    srand(clock());

    int * perm = (int *) malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++){
        perm[i] = i;
    }

    for(int i = 0; i < N; i++){
        int j = (rand() % (N-i)) + i; //[] i, N-1]
        //swap i and j
        int tmp = perm[i];
        perm[i] = perm[j];
        perm[j] = tmp;

    }
    clock_t start = clock();

    //O(1) [best case]
    //O(N) [worst case: at the end]
    //O(N) [average case: weighted sum]
    //AVG analysis:
    //SUM ( Steps taken * probability )
    //AVG = 1(1/N) + 2(1/N) + 3(1/N) + ... + N(1/N)
    //    = (1+2+3+ ... + N)(1/N)
    //    = (N + 1) / 2
    for(int i = 0; i < N; i++){
        if(perm[i] == 0){
            printf("%d is @ location %d\n", perm[i], i);
            break;
        }

    }
    clock_t end = clock();
    printf("clock taken %ld\n", start - end);


    return 0 ;

}