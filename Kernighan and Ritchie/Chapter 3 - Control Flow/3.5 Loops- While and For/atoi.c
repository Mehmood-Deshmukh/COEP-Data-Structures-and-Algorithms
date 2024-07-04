#include <stdio.h>
#include <ctype.h>

int atoi(char s[]);
int main() {
    char s[] = "12345";
    printf("%d\n", atoi(s));
    return 0;
}

int atoi(char s[]){
    int i, n , sign;
    for (i = 0; isspace(s[i]); i++);

    sign = (s[i] == '-') ? -1:1;
    if (s[i] == '+' || s[i] == '-'){
        i++;
    }

    for(n = 0; isdigit(s[i]); i++){
        n = n*10 + (s[i] - '0');
    }

    return sign*n;
}