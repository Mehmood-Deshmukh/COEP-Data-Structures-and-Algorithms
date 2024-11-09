typedef struct Node{
    int data;
    struct Node *next;
} Node;

typedef struct Queue{
    Node *head;
    Node *tail;
} Queue;

void init_queue(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
int is_empty(Queue q);
int peek(Queue q);
void display(Queue q);