#include <stdio.h>
#include <stdlib.h>
#include "./header.h"

//macro for MAX of two elements irrespective of datatype
#define MAX(a, b) ((a) > (b) ? (a) : (b))

//function to initialize the polynomial
void init(Polynomial *p, int maxDegree){
    p->maxDegree = maxDegree; //set the maxDegree
    p->A = (int *) calloc(maxDegree + 1, sizeof(int)); //use calloc to initialize with zeroes
}

//function to append a term 
void append(Polynomial *p, int coefficient, int degree){
    //check for invalid condition or if coefficient is zero
    if (degree > p->maxDegree || degree < 0 || coefficient == 0) return;
    //add the coefficient to the corresponding degree's coefficient
    p->A[degree] += coefficient;
    return;
}

//function to display the polynomial
void display(Polynomial p){
    int i; //for iteration
    int maxDegree = p.maxDegree; //get the maxDegree
    
    for(i = maxDegree; i >= 0; i--){ //traverse through entire array
        if(p.A[i] == 0) continue; // if coefficient is 0 we dont print

        if(i == 0){ // if degree is zero we dont print the variable
            printf("(%d)\n",p.A[i]);
            return;
        }else if(p.A[i] == 1){ // if coeffcient is 1
            if (i == 1){ //if degree is also one we just print variable x
                printf("x + ");
            }else{
                printf("x^(%d) + ", i); //else just print x with the corresponding degree
            }

        }else if (i == 1){
            printf("(%d)x + ", p.A[i]); //if degree is one we dont show power using '^'
        }else{
            printf("(%d)x^(%d) + ", p.A[i], i); //general case (coeff)x^(degree)
        }
    }

    printf("\b\b \n"); //remove ending '+'
}

//function to get entire polynomial at once from user
void getPolynomial(Polynomial *p, int maxDegree){
    int coefficient;
    for(int i = maxDegree; i >= 0; i--){ //ask coefficient for each degree
        printf("Enter Coefficient of x^(%d)\n", i);
        scanf("%d", &coefficient);
        append(p, coefficient, i); //append the term
    }

    return;
}

//fill polynomial with random coefficients
void randomPolynomial(Polynomial *p, int maxDegree){
    int coefficient;
    for(int i = maxDegree; i >= 0; i--){
        coefficient = rand() % 100 + 1; //get random coefficient from 1 to 100
        append(p, coefficient, i); //append the term
    }

    return;
}


//function to add two polynomials
Polynomial add(Polynomial a, Polynomial b){
    int maxA = a.maxDegree, maxB = b.maxDegree; //get maxDegrees of both polynomials
    int maxDegree = MAX(maxA, maxB); //the maxDegree of result will be the max of degrees of the two polynomials
    Polynomial result;
    init(&result, maxDegree); //initialize the result polynomial
    int i = maxA, j = maxB;
    while (i >= 0 && j >= 0){
        if (i == j){ //if terms with same degree are present for both polynomials append term to result with addition of coefficients of the two terms
            append(&result, a.A[i] + b.A[j], i);
            i--;
            j--;
        }else if (i > j){
            append(&result, a.A[i], i); //add term from polynomial where the term with degree exists
            i--;
        }else{
            append(&result, b.A[j], j); //add term from polynomial where the term with degree exists
            j--;
        }
    }

    //add remaining terms (if any left)
    while (i >= 0){
        append(&result, a.A[i], i);
        i--;
    }
    
    //add remaining terms (if any left)
    while (j >= 0){
        append(&result, b.A[j], j);
        j--;
    }

    return result;
}

//function to substract two polynomials
Polynomial substract(Polynomial a, Polynomial b){
    int maxA = a.maxDegree, maxB = b.maxDegree; //get maxDegrees of both polynomials
    int maxDegree = MAX(maxA, maxB); //the maxDegree of result will be the max of degrees of the two polynomials
    Polynomial result;
    init(&result, maxDegree);  //initialize the result polynomial
    int i = maxA, j = maxB;
    while (i >= 0 && j >= 0){
        if (i == j){ //if terms with same degree are present for both polynomials append term to result with substraction of coefficients of the two terms
            append(&result, a.A[i] - b.A[j], i);
            i--;
            j--;
        }else if (i > j){
            append(&result, a.A[i], i); //add term from first polynomial where the term with degree exists
            i--;
        }else{
            append(&result, -b.A[j], j);//add negation of term from second polynomial where the term with degree exists
            j--;
        }
    }

    //add remaining terms from first polynomial (if any left)
    while (i >= 0){
        append(&result, a.A[i], i);
        i--;
    }
    
    ///add negation of remaining terms from second polynomial (if any left)
    while (j >= 0){
        append(&result, -b.A[j], j);
        j--;
    }    

    return result;
}

//function to multiply two polynomials
Polynomial multiply(Polynomial a, Polynomial b) {
    int maxA = a.maxDegree, maxB = b.maxDegree; //get maxDegrees of both polynomials
    int maxDegree = maxA + maxB; //the maxDegree of result will be the sum of degrees of the two polynomials
    Polynomial result; 
    init(&result, maxDegree);  //initialize the result polynomial

    // multiply each term of first polynomial with each term of the second polynomial and append it to the result
    for (int i = 0; i <= maxA; i++) {
        for (int j = 0; j <= maxB; j++) {
            int newCoeff = a.A[i] * b.A[j];
            int newDegree = i + j;
            append(&result, newCoeff, newDegree);
        }
    }

    return result;
}
