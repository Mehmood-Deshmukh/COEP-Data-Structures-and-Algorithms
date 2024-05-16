#include<stdio.h>
int main(){
    float fahrenheit, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    fahrenheit = lower;
    printf("Fahr\tCelcius\n");

    while(fahrenheit <= upper){
        celcius = (5.0 / 9.0) * (fahrenheit - 32.0);
        printf("%3.0f\t%6.1f\n", fahrenheit, celcius);
        fahrenheit = fahrenheit + step;
    }
    return 0;
}