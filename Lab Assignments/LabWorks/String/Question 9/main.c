#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EPSILON 1e-10

double factorial(int n) {
    if (n == 0 || n == 1) return 1;
    double foactorial = 1;
    for (int i = 2; i <= n; i++) {
        foactorial *= i;
    }
    return foactorial;
}

double normalize_angle(double x) {
    while (x > PI) x -= 2 * PI;
    while (x < -PI) x += 2 * PI;
    return x;
}

double sine(double x) {
    x = normalize_angle(x);
    double term = x;
    double sum = x;
    int n = 1;

    while (fabs(term) > EPSILON) {
        term *= -x * x / ((2 * n) * (2 * n + 1));
        sum += term;
        n++;
    }

    return sum;
}


double cosine(double x) {
    x = normalize_angle(x);
    double term = 1;
    double sum = 1;
    int n = 1;

    while (fabs(term) > EPSILON) {
        term *= -x * x / ((2 * n - 1) * (2 * n));
        sum += term;
        n++;
    }

    return sum;
}

double sine_inverse(double x) {
    double term = x;
    double sum = x;
    int n = 1;

    while (fabs(term) > EPSILON) {
        term *= x * x * (2 * n - 1) / ((2 * n + 1) * (2 * n));
        sum += term;
        n++;
    }

    return sum;
}

double cosine_inverse(double x) {
    return PI / 2 - sine_inverse(x);
}

double tan(double x) {
    return sine(x) / cosine(x);
}

int main() {
    double x = PI / 4;

    double sine_value = sine(x);
    double cosine_value = cosine(x);
    double tan_value = tan(x);
    
    printf("x = %f\n", x);
    printf("sin(x) = %f\n", sine_value);
    printf("cos(x) = %f\n", cosine_value);
    printf("tan(x) = %f\n", tan_value);

    double sine_inverse_value = sine_inverse(sine_value);
    double cosine_inverse_value = cosine_inverse(cosine_value);
    
    printf("sin^-1(sin(x)) = %f\n", sine_inverse_value);
    printf("cos^-1(cos(x)) = %f\n", cosine_inverse_value);
    

    printf("Error in sin^-1(sin(x)): %e\n", fabs(x - sine_inverse_value));
    printf("Error in cos^-1(cos(x)): %e\n", fabs(x - cosine_inverse_value));

    return 0;
}
