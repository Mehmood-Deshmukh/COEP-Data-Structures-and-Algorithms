#include <stdio.h>

int strlen(char *s);
int main() {
    printf("%d", strlen("mehmood"));
    return 0;
}

int strlen(char *s){
    int n;

    for (n = 0;  *s != '\0'; s++){
        n++;
    }
    
    return n;
}