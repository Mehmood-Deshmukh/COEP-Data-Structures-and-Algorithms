typedef struct Node{
    int coefficient;
    int degree;
    struct Node *next;
} Node;

typedef struct Polynomial{
    int max_degree;
    Node *head;
} Polynomial;

void init(Polynomial *p);
void append(Polynomial *p, int coefficient, int degree);
void display(Polynomial p);
void random_polynomial(Polynomial *p, int max_degree);
void get_polynomial(Polynomial *p, int max_degree);
Polynomial add(Polynomial p1, Polynomial p2);
Polynomial substract(Polynomial p1, Polynomial p2);
Polynomial multiply(Polynomial p1, Polynomial p2);




