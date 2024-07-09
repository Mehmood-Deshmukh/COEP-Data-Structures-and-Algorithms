#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char line[], int max);
int strindex(char source[], char searchfor[]);

int main(int argc,  char *argv[]) {

    char line[MAXLINE];
    int found = 0;

    if (argc != 2){
        printf("Usage: find pattern");
    }else{
        while (get_line(line, MAXLINE) > 0){
            if (strindex(line, argv[1]) >= 0){
                printf("%s", line);
                found++;
            }
        }    
    }
    
    return found;
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


int strindex(char s[], char t[]){
    for(int i = 0; s[i] != '\0'; i++){
        int k = 0;
        for(int j = i; t[k] != '\0' && s[j] == t[k]; j++, k++);
        if(k > 0 && t[k] == '\0'){
            return i;
        }
    }
    return -1;
}