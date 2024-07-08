#define ALLOCSIZE 10000

static char allocbuff[ALLOCSIZE];
static char *allocp = allocbuff;

char *alloc(int n);
void afree(char *p);

char *alloc(int n){
    if (allocbuff + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    } else{
        return 0;
    }
}

void afree(char *p){
    if (p >= allocbuff && p < allocbuff + ALLOCSIZE){
        allocp = p;
    }
    
}

