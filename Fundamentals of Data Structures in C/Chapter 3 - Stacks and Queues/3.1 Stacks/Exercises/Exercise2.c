#include <stdio.h>

int recursiveBinomialCoefficient(int n, int k);
int iterativeBinomialCoefficient(int n, int k);
int factorial(int n);

int main() {
    printf("%d\n", recursiveBinomialCoefficient(5, 4));
    printf("%d\n", iterativeBinomialCoefficient(5, 4));
    return 0;
}

int recursiveBinomialCoefficient(int n, int k){
    if (k == 0 || k == n) {
        return 1;
    }
    
    return recursiveBinomialCoefficient(n - 1, k - 1) + recursiveBinomialCoefficient(n - 1, k);
}

int iterativeBinomialCoefficient(int n, int k){
    if (k > n) {
        return 0;
    }

    return factorial(n) / (factorial(k) * factorial(n - k));
}

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}