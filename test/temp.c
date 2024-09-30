//rite following functions: sine, sine-inverse, cosine, cosine-inverse. Then using sine and 
// cosine, write tan() function. Check whether calling sine(sine-inverse(x)) on your own 
// functions gives you x.

#include <stdio.h>
#include <math.h>

// instead of using direct values its better to define macros
#define PI 3.14159265358979323846
#define EPSILON 1e-10

// function to normalize the angle . used in sine and cosine calculation
double normalize_angle(double x) {
    while (x > PI) x -= 2 * PI;
    while (x < -PI) x += 2 * PI;
    return x;
}

//function which uses the taylor series to calculate sine
double sine(double x) {
    x = normalize_angle(x);
    double term = x;
    double sum = x;
    int n = 3;

    while (fabs(term) > EPSILON) {
        term *= -x * x / ((n) * (n - 1));
        sum += term;
        n += 2;
    }

    return sum;
}

//function which uses the taylor series to calculate cosine
double cosine(double x) {
    x = normalize_angle(x);
    double term = 1;
    double sum = 1;
    int n = 2;

    while (fabs(term) > EPSILON) {
        term *= -x * x / ((n) * (n - 1));
        sum += term;
        n += 2;
    }

    return sum;
}

//function which uses the taylor series to calculate sine-inverse
double sine_inverse(double x) {
    double term = x;
    double sum = x;
    int n = 1;

    while (fabs(term) > EPSILON) {
        term *= x * x * (2 * n - 1) * (2 * n - 1) / ((2 * n + 1) * (2 * n));
        sum += term;
        n++;
    }

    return sum;
}

// function which uses the formula: cos^-1(x) = PI/2 - sin^-1(x)
double cosine_inverse(double x) {
    return PI / 2 - sine_inverse(x);
}

// function which uses the formula: tan(x) = sin(X) / cos(x)
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

    return 0;
}
