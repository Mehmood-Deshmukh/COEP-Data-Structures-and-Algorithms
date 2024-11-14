typedef struct Stack {
    int top;
    int size;
    int *array;
} Stack;

void init(Stack *s, int size);
int is_empty(Stack s);
int is_full(Stack s);
void push(Stack *s, int data);
int peek(Stack s);
int pop(Stack *s);
void display(Stack s);
void sort(Stack *s);