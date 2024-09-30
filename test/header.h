#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int coefficient;
    int degree;
    struct Node *next;
} Node;

typedef struct Polynomial{
    int maxDegree;
    Node *head;
} Polynomial;

void init(Polynomial *p);
void append(Polynomial *p, int coefficient, int degree);
void display(Polynomial p);
Polynomial add(Polynomial p1, Polynomial p2);
Polynomial substract(Polynomial p1, Polynomial p2);
Polynomial multiply(Polynomial p1, Polynomial p2);




