#include <stdio.h>
#define NSYM 1
struct {
    char *name;
    int flags;
    int utype;
    union {
        int ival;
        float fval;
        char *sval;
    } u;
} symtab[NSYM];

int main() {
    union u_tag{
        int ival;
        float fval;
        char *sval;
    } u;

    


    
    return 0;
}