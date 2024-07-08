#include <stdio.h>

void _strcpy(char *s, char *t);
int main() {
    char s[] = "not mehmood";
    char t[] = "mehmood";
    printf("Before = %s\n", s);
    _strcpy(s, t);
    printf("After = %s", s);

    return 0;
}
void _strcpy(char *s, char *t){
    while (*s++ = *t++);
}