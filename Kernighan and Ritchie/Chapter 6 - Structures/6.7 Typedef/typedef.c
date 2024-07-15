#include <stdio.h>
#include <stdlib.h>
#define MAXLINES 20

typedef struct tnode *Treeptr;
typedef struct tnode{
    char *word;
    int count;
    Treeptr left;
    Treeptr right;
} Treenode;

Treeptr talloc(void){
    return (Treeptr) malloc(sizeof(Treenode));
}

int main() {
    typedef int Length;
    Length len, maxlen;
    Length *lengths[1];

    typedef char *String;
    String p, lineptr[MAXLINES], alloc(int);
    int strcmp(String, String);
    p = (String) malloc(100);
    free(p);

    typedef int (*PFI) (char *, char *);

    PFI numcmp;

    return 0;
}