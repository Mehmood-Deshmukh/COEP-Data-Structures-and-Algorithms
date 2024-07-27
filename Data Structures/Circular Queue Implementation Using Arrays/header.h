typedef struct Queue{
    int head, tail, count, size;
    int *Q;
} Queue;

void init(Queue *q, int size);
void enQueue(Queue *q, int data);
int deQueue(Queue *q);
int isEmpty(Queue q);
int isFull(Queue q);
int peek(Queue q);
void display(Queue q);