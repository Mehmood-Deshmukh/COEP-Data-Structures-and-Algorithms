#include<stdio.h>
#include<string.h>
#define MAXLEN 1000

int _getline(char line[], int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = _getline(line, MAXLEN)) > 0){
        if (nlines > maxlines || (p = alloc(len)) == NULL){
            return -1;
        } else{
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}

int _getline(char line[], int maxline){
    int c, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n' ; ++i) {
        line[i] = c;
    }
    
    if (c == '\n'){
        line[i++] = c; 
    }

    line[i] = '\0';
    return i;
}


void writelines(char *lineptr[], int nlines){
    while (nlines -- > 0){
        printf("%s\n", *lineptr++);
    }
}