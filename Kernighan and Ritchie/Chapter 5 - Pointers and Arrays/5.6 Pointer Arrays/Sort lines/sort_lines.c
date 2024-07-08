#include <stdio.h>
#include <string.h>

#define MAXLINE 5000

char *lineptr[MAXLINE];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main() {

    int nlines;

    if ((nlines = readlines(lineptr, MAXLINE)) >= 0){
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;   
    }else{
        printf("error: input too big to sort\n");
        return 1;
    }
}
