#include <stdio.h>

void _strcat(char s[], char t[]);

int main() {
    char s[] = "mehmood ";
    char t[] = "was here";
    _strcat(s,t);
    printf("%s", s);
    return 0;
}

void _strcat(char s[], char t[]){
    int i = 0, j= 0;
    while (s[i] != '\0'){
        i++;
    }

    while ((s[i++] = t[j++] )!= '\0');    
}
