typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef Node *Stack;

void init(Stack *s);
void push(Stack *s, int data);
int pop(Stack *s);
int peek(Stack s);
int is_empty(Stack s);
void display(Stack s);
void sort(Stack *s);