typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

typedef StackNode *Stack;

void init_stack(Stack *s);
void push(Stack *s, int data);
int pop(Stack *s);
int peek_stack(Stack s);
int is_empty_stack(Stack s);
void display_stack(Stack s);
void free_stack(Stack *s);