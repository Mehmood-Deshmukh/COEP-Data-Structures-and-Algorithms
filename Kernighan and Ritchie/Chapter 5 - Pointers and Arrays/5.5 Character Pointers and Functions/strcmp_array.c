#include <stdio.h>

int _strcmp(char *s, char *t);
int main() {
    char s[] = "mehmood";
    char t[] = "mehmood";
    printf("%d", _strcmp(s, t));

    return 0;
}
int _strcmp(char *s, char *t){
    int i;

    for(i = 0; s[i] == t[i]; i++){
        if (s[i] == '\0'){
            return 0;
        }
    }

    return s[i] - t[i];
}