typedef struct cNode {
    char data;
    struct cNode *next;
} cNode;

typedef cNode *cStack;

void cinit(cStack *s);
void cpush(cStack *s, char data);
char cpop(cStack *s);
char cpeek(cStack s);
int cisEmpty(cStack s);
void cdisplay(cStack s);