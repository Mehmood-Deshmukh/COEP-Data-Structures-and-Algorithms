#include <stdio.h>
#include <stdlib.h>
#include "./header.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void init(Polynomial *p, int maxDegree){
    p->maxDegree = maxDegree;
    p->A = (int *) calloc(maxDegree + 1, sizeof(int));
}

void append(Polynomial *p, int coefficient, int degree){
    if (degree > p->maxDegree || degree < 0 || coefficient == 0) return;
    p->A[degree] += coefficient;
    return;
}

void display(Polynomial p){
    int i;
    int maxDegree = p.maxDegree;
    
    for(i = maxDegree; i >= 0; i--){
        if(p.A[i] == 0) continue;

        if(i == 0){
            printf("(%d)\n",p.A[i]);
            return;
        }else if(p.A[i] == 1){
            if (i == 1){
                printf("x + ");
            }else{
                printf("x^(%d) + ", i);
            }

        }else if (i == 1){
            printf("(%d)x + ", p.A[i]);
        }else{
            printf("(%d)x^(%d) + ", p.A[i], i);
        }
    }

    printf("\b\b \n");
}
void getPolynomial(Polynomial *p, int maxDegree){
    int coefficient;
    for(int i = maxDegree; i >= 0; i--){
        printf("Enter Coefficient of x^(%d)\n", i);
        scanf("%d", &coefficient);
        append(p, coefficient, i);
    }

    return;
}
void randomPolynomial(Polynomial *p, int maxDegree){
    int coefficient;
    for(int i = maxDegree; i >= 0; i--){
        coefficient = rand() % 201 - 100;
        append(p, coefficient, i);
    }

    return;
}

Polynomial add(Polynomial a, Polynomial b){
    int maxA = a.maxDegree, maxB = b.maxDegree;
    int maxDegree = MAX(maxA, maxB);
    Polynomial result;
    init(&result, maxDegree);
    int i = maxA, j = maxB;
    while (i >= 0 && j >= 0){
        if (i == j){
            append(&result, a.A[i] + b.A[j], i);
            i--;
            j--;
        }else if (i > j){
            append(&result, a.A[i], i);
            i--;
        }else{
            append(&result, b.A[j], j);
            j--;
        }
    }

    while (i >= 0){
        append(&result, a.A[i], i);
        i--;
    }
    
    while (j >= 0){
        append(&result, b.A[j], j);
        j--;
    }

    

    return result;
}
Polynomial substract(Polynomial a, Polynomial b){
    int maxA = a.maxDegree, maxB = b.maxDegree;
    int maxDegree = MAX(maxA, maxB);
    Polynomial result;
    init(&result, maxDegree);
    int i = maxA, j = maxB;
    while (i >= 0 && j >= 0){
        if (i == j){
            append(&result, a.A[i] - b.A[j], i);
            i--;
            j--;
        }else if (i > j){
            append(&result, a.A[i], i);
            i--;
        }else{
            append(&result, -b.A[j], j);
            j--;
        }
    }

    while (i >= 0){
        append(&result, a.A[i], i);
        i--;
    }
    
    while (j >= 0){
        append(&result, -b.A[j], j);
        j--;
    }    

    return result;
}
Polynomial multiply(Polynomial a, Polynomial b) {
    int maxA = a.maxDegree, maxB = b.maxDegree;
    int maxDegree = maxA + maxB;
    Polynomial result;
    init(&result, maxDegree);

    for (int i = 0; i <= maxA; i++) {
        for (int j = 0; j <= maxB; j++) {
            int newCoeff = a.A[i] * b.A[j];
            int newDegree = i + j;
            append(&result, newCoeff, newDegree);
        }
    }

    return result;
}
