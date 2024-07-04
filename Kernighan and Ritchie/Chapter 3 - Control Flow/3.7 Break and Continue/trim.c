#include <stdio.h>
#include <string.h>
int trim(char s[]);
int main() {
    char str[] = "mehmood          ";
    printf("%s%d\n", str, 1);
    trim(str);
    printf("%s%d", str, 1);
    return 0;
}

int trim(char s[]){
    int n;

    for (n = strlen(s) - 1; n >= 0; n--){
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n'){
            break;
        }
    }
    s[n + 1] = '\0';
    return n;
    
}