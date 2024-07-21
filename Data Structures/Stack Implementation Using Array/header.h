typedef struct Stack {
    int top;
    int size;
    int *array;
} Stack;

void init(Stack *s, int size);
int isEmpty(Stack s);
int isFull(Stack s);
void push(Stack *s, int data);
int peek(Stack s);
int pop(Stack *s);
void display(Stack s);