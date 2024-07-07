#include <stdio.h>
#include <ctype.h>

#define SIZE 10

int getch(void);
int ungetch(int);
int getint(int *pn);
int main() {
    int n, array[SIZE];
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++);

    for(int i = 0; i < SIZE; i++){
        printf("%d ", array[i]);
    }
    
    return 0;
}


int getint(int *pn){
    int c, sign;

    while (isspace(c = getch()));

    if (!isdigit(c) && c!= EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c =='-'){
        c = getch();
    }
    for(*pn = 0; isdigit(c); c = getch()){
        *pn = *pn * 10 + (c - '0');
    }

    *pn = *pn * sign;

    if (c != EOF){
        ungetch(c);
    }

    return c;
}