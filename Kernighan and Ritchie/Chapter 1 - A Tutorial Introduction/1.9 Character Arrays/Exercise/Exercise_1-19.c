#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
int get_length(char line[]);
char* reverse(char line[], int length);

int main() {
    int len;
    char line[MAXLINE];

    while((len = get_line(line , MAXLINE)) > 0){
        printf("reversed : %s", reverse(line, len));
    }
    return 0;
}

int get_line(char line[], int maxline){
    int c, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n' ; ++i) {
        if(c == ' ' || c == '\t'){
            --i;
            continue;
        }
        line[i] = c;
    }
    
    if (c == '\n'){
        line[i++] = c; 
    }

    line[i] = '\0';
    return i;
}

char* reverse(char line[], int length){
    for(int i = 0; i < length/2; i++){
        char temp = line[i];
        line[i] = line[length - i - 1];
        line[length - i - 1] = temp;
    }

    return line;
}