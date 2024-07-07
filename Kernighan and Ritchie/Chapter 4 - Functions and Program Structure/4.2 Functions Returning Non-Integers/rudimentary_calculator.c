#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

int get_line(char line[], int max);
double atof(char s[]);

int main() {
    double sum = 0;
    char line[MAXLINE];
    while (get_line(line, MAXLINE) > 0){
        printf("\t%g\n", sum+=atof(line));
    }
    
    return 0;
}

int get_line(char line[], int lim){
    int c, i = 0;

    while (lim-- > 0 && (c = getchar()) != EOF && c != '\n'){
        line[i++] = c;
    }

    if (c == '\n'){
        line[i++] = '\n';
    }
    

    line[i]  = '\0';
    return i;
}

double atof(char s[]){
    double val ,power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++);

    sign = (s[i] == '-')? -1:1;

    if (s[i] == '+' || s[i] == '-'){
        i++;   
    }

    for (val = 0.0; isdigit(s[i]); i++){
        val  = val * 10.0 + (s[i] - '0');
    }

    if (s[i] == '.'){
        i++;
    }

    for(power = 1.0; isdigit(s[i]); i++){
        val  = val * 10.0 + (s[i] - '0');
        power *= 10.0;
    }


    return sign * (val/power);    
}