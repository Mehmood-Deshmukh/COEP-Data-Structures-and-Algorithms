typedef struct Node{
    char data;
    struct Node *next;
} Node;

typedef Node *Queue;

void init(Queue *q);
void enQueue(Queue *q, char data);
char deQueue(Queue *q);
int isEmpty(Queue q);
char peek(Queue q);
void display(Queue q);