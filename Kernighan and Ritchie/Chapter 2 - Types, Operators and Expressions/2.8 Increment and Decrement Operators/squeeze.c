#include <stdio.h>

void squeeze(char s[], int c);
int main() {
    char s[] = "mehmood";
    squeeze(s, 'o');
    printf("%s", s);
    return 0;
}

void squeeze(char s[], int c){
    int i = 0, j = 0;

    for(;s[i]!='\0';i++){
        if(s[i]!= c){
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}