typedef struct Stack {
    int top;
    int size;
    int *array;
} Stack;

#define SIZE 10

void init(Stack *s);
int is_empty(Stack s);
void is_full(Stack *s);
void push(Stack *s, int data);
int peek(Stack s);
int pop(Stack *s);
void display(Stack s);
void sort(Stack *s);