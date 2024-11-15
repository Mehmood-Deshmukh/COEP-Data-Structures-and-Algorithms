#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Polynomial p1, p2, sum, difference, product;
    init(&p1, 4);
    init(&p2, 5);
    get_polynomial(&p1, 4);
    random_polynomial(&p2, 5);
    printf("Polynomial 1: ");
    display(p1);
    printf("Polynomial 2: ");
    display(p2);

    sum = add(p1, p2);
    printf("Sum: ");
    display(sum);

    difference = substract(p1, p2);
    printf("Difference: ");
    display(difference);

    product = multiply(p1, p2);
    printf("Product: ");
    display(product);
    return 0;
}