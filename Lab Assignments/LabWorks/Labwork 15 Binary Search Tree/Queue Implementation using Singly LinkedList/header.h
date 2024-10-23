typedef struct Node{
    int data;
    struct Node *next;
} Node;

typedef struct Queue{
    Node *head;
    Node *tail;
} Queue;

void qinit(Queue *q);
void enQueue(Queue *q, int data);
int deQueue(Queue *q);
int isEmpty(Queue q);
int peek(Queue q);
void display(Queue q);
int getSize(Queue q);