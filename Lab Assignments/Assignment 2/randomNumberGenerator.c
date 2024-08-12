#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main(){
    int n, max;
    time_t t;
    scanf("%d%d", &n, &max);
    srand(time(&t));
    for(int i = 0; i < n; i++){
        printf("%ld\n", (long) rand() % max);
    }
    return 0;
}