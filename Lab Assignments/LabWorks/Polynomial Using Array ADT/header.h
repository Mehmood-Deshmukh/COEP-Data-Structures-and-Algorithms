typedef struct Polynomial{
    int maxDegree;
    int *A;
} Polynomial;

void init(Polynomial *p, int maxDegree);
void append(Polynomial *p, int coefficient, int degree);
void display(Polynomial p);
Polynomial add(Polynomial p1, Polynomial p2);
Polynomial substract(Polynomial p1, Polynomial p2);
Polynomial multiply(Polynomial p1, Polynomial p2);