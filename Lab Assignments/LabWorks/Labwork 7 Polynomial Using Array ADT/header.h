//typedef of structure
typedef struct Polynomial{
    int maxDegree; //the maximum degree of the polynomial
    int *A; //a pointer to a series of integers representing the coefficients
} Polynomial;

//function prototypes
void init(Polynomial *p, int maxDegree);
void append(Polynomial *p, int coefficient, int degree);
void display(Polynomial p);
Polynomial add(Polynomial p1, Polynomial p2);
Polynomial substract(Polynomial p1, Polynomial p2);
Polynomial multiply(Polynomial p1, Polynomial p2);