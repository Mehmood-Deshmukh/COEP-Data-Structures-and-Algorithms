#include<stdio.h>

float fahrenheit_to_celcius(float fahrenheit);
int main(){
    float fahrenheit, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    fahrenheit = lower;
    while(fahrenheit <= upper){
        celcius = fahrenheit_to_celcius(fahrenheit);
        printf("%3.0f %6.1f\n", fahrenheit, celcius);
        fahrenheit = fahrenheit + step;
    }
    return 0;
}

float fahrenheit_to_celcius(float fahrenheit){
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}