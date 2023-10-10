
#include <stdio.h>

// permutation of 1, 2, 3, 4, ... n
// 1, 2, 3, 4
// 1, 2, 4, 3
// 1, 3, 2, 4
// 1, 3, 4, 2
// ...

int count = 0;

// Print Permutation function
void printPerm(int * perm, int n) {
    printf("%-5d", ++count);
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}

// permutation function
// number of values in perm, perm, used array, index
void permute(int n, int * perm, int * used, int index) {
    // Base Case
    if (index == n) {
        // Print the permutation
        printPerm(perm, n);
        // Stop
        return;
    }

    // Recursive Case: Try all unused values
    for (int i = 0; i < n; i++){
        if (!used[i]) {
            // Use the i-th value in the permutation at the given index
            used[i] = 1;
            perm[index] = i + 1;

            // Generate a permutation of the remaining values
            permute(n, perm, used, index + 1);

            // Unuse the i-th value in the permutation at the given index
            used[i] = 0;
            perm[index] = 0;
        }
    }
}

// main
//  - permute
//      1 - permute
//          2 - permute
//              3 - permute
//                  4 - permute
//                      5 - permute (BASE CASE)
//                  5 - permute
//                      4 - permute (BASE CASE)
//              4 - permute
//                  3 - permute
//                      5 - permute (BASE CASE)
//

// main function
int main() {
    int n = 5;
    int perm[n];
    int used[n];

    // Intialize array
    for (int i = 0; i < n; i++) {
        perm[i] = 0;
        used[i] = 0;
    }

    permute(n, perm, used, 0);

    return 0;
}
