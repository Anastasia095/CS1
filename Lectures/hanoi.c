#include <stdio.h>

int hanoi(int n, char * s, char * e, char * a){
    if (n == 0){
        return 0;
    }
    int ans = 0;
    ans += hanoi(n-1,s,a,e);
    hanoi(n-1, s, a, e);
    printf("Move disck %d from %s to %s\n", n, s, e);
    ans++;

    ans+= hanoi(n-1,a,e,s);

    return ans;
}

int main(){
    printf("It took %d moves \n", hanoi(10, "START", "END", "AUX"));

    return 0;
}