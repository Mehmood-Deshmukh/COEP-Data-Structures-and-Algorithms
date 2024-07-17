#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
char *strdup(char *s);

struct nlist{
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];

int main() {
    
    return 0;
}


unsigned hash(char *s){
    unsigned hashval;

    for(hashval = 0; *s != '\0'; s++){
        hashval = *s + 31 * hashval;
    }

    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s){
    struct nlist *np;

    for(np = hashtab[hash(s)]; np != NULL; np = np->next){
        if(strcmp(s, np->name) == 0){
            return np;
        }
    }
    return NULL;
}

char *strdup(char *s){
    char *p;

    p = (char *)malloc(strlen(s) + 1);
    if (p != NULL){
        strcpy(p, s);
    }

    return p;
}
