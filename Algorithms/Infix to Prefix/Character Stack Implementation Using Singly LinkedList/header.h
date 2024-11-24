typedef struct Node {
    char data;
    struct Node *next;
} Node;

typedef Node *Stack;

void init(Stack *s);
void push(Stack *s, char data);
char pop(Stack *s);
char peek(Stack s);
int is_empty(Stack s);
void display(Stack s);