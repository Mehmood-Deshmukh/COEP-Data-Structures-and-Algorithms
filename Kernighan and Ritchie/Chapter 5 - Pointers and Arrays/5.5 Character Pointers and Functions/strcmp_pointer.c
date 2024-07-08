#include <stdio.h>

int _strcmp(char *s, char *t);
int main() {
    char s[] = "mehmood";
    char t[] = "mehmood";
    printf("%d", _strcmp(s, t));

    return 0;
}
int _strcmp(char *s, char *t){
    for(; *s == *t; s++, t++){
        if (*s == '\0'){
            return 0;
        }
    }

    return *s - *t;
}