#include <stdio.h>
#include <stdlib.h>
#include "./header.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void init(Polynomial *p, int max_degree){
    p->max_degree = max_degree;
    p->array = (int *) calloc(max_degree + 1, sizeof(int));
}

void append(Polynomial *p, int coefficient, int degree){
    if (degree > p->max_degree || degree < 0 || coefficient == 0) return;
    p->array[degree] += coefficient;
    return;
}

void display(Polynomial p){
    for(int i = p.max_degree; i >= 0; i--){
        if(!p.array[i]) continue;

        printf("(%d)x^(%d) + ", p.array[i], i);
    }

    printf("\b\b \n");
}


void get_polynomial(Polynomial *p, int max_degree){
    int coefficient;
    for(int i = max_degree; i >= 0; i--){
        printf("Enter Coefficient of x^(%d)\n", i);
        scanf("%d", &coefficient);
        append(p, coefficient, i);
    }

    return;
}

void random_polynomial(Polynomial *p, int max_degree){
    int coefficient;
    for(int i = max_degree; i >= 0; i--){
        coefficient = rand() % 201 - 100;
        append(p, coefficient, i);
    }

    return;
}

Polynomial add(Polynomial a, Polynomial b){
    int max_a = a.max_degree, max_b = b.max_degree;
    int max_degree = MAX(max_a, max_b);
    Polynomial result;
    init(&result, max_degree);
    int i = max_a, j = max_b;
    while (i >= 0 && j >= 0){
        if (i == j){
            append(&result, a.array[i] + b.array[j], i);
            i--;
            j--;
        }else if (i > j){
            append(&result, a.array[i], i);
            i--;
        }else{
            append(&result, b.array[j], j);
            j--;
        }
    }

    while (i >= 0){
        append(&result, a.array[i], i);
        i--;
    }
    
    while (j >= 0){
        append(&result, b.array[j], j);
        j--;
    }

    

    return result;
}

Polynomial substract(Polynomial a, Polynomial b){
    int max_a = a.max_degree, max_b = b.max_degree;
    int max_degree = MAX(max_a, max_b);
    Polynomial result;
    init(&result, max_degree);
    int i = max_a, j = max_b;
    while (i >= 0 && j >= 0){
        if (i == j){
            append(&result, a.array[i] - b.array[j], i);
            i--;
            j--;
        }else if (i > j){
            append(&result, a.array[i], i);
            i--;
        }else{
            append(&result, -b.array[j], j);
            j--;
        }
    }

    while (i >= 0){
        append(&result, a.array[i], i);
        i--;
    }
    
    while (j >= 0){
        append(&result, -b.array[j], j);
        j--;
    }    

    return result;
}

Polynomial multiply(Polynomial a, Polynomial b) {
    int max_a = a.max_degree, max_b = b.max_degree;
    int max_degree = max_a + max_b;
    Polynomial result;
    init(&result, max_degree);

    for (int i = 0; i <= max_a; i++) {
        for (int j = 0; j <= max_b; j++) {
            int newCoeff = a.array[i] * b.array[j];
            int newDegree = i + j;
            append(&result, newCoeff, newDegree);
        }
    }

    return result;
}
