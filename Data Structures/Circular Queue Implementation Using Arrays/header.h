typedef struct Queue{
    int head, tail, length, size;
    int *array;
} Queue;

void init(Queue *q, int size);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
int is_empty(Queue q);
int is_full(Queue q);
int peek(Queue q);
void display(Queue q);