typedef struct QueueNode{
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue{
    QueueNode *head;
    QueueNode *tail;
} Queue;

void init_queue(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
int is_empty_queue(Queue q);
int peek_queue(Queue q);
void display_queue(Queue q);