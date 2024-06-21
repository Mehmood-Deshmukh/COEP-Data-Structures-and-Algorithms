#include <stdio.h>

int strlen(char s[]);
int main() {
    printf("%d", strlen("mehmood was here"));
    return 0;
}

int strlen(char s[]){
    int i = 0;
    while (s[i] != '\0'){
        i++;
    }
    return i;
}