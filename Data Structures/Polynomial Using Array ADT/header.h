typedef struct Polynomial{
    int max_degree;
    int *array;
} Polynomial;

void init(Polynomial *p, int max_degree);
void append(Polynomial *p, int coefficient, int degree);
void display(Polynomial p);
void get_polynomial(Polynomial *p, int max_degree);
void random_polynomial(Polynomial *p, int max_degree);
Polynomial add(Polynomial p1, Polynomial p2);
Polynomial substract(Polynomial p1, Polynomial p2);
Polynomial multiply(Polynomial p1, Polynomial p2);




