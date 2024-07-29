#include <stdio.h>
#include <string.h>

void perm(char *list, int i, int n);
void swap(char *x, char *y);

int main() {
    char str[] = "abcd";
    perm(str, 0, strlen(str) - 1);
    return 0;
}

void swap(char *x, char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}

void perm(char *list, int i, int n){
    int j;
    if(i == n){
        for(j = 0; j <= n; j++){
            printf("%c", list[j]);
        }
        printf("   ");
    }else{
        for(j = i; j <= n; j++){
            swap(&list[i], &list[j]);
            perm(list, i + 1, n);
            swap(&list[i], &list[j]);
        }
    }

}