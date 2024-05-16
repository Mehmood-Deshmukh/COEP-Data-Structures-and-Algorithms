#include<stdio.h>
int main(){
    float fahrenheit, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    celcius = lower;
    printf("Cel\tFahrenheit\n");

    while(celcius <= upper){
        fahrenheit = (9.0 / 5.0) * (celcius) + 32.0;
        printf("%3.0f\t%6.1f\n", celcius, fahrenheit);
        celcius = celcius + step;
    }
    return 0;
}