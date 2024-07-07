#include <stdio.h>

int strlen(char *s);
int main() {
    printf("%d", strlen("mehmood"));
    return 0;
}

int strlen(char *s){
    char *p = s;

    while (*p != '\0'){
        p++;
    }
    
    
    return p - s;
}