// 18. The wind chill index (WCI) is calculated from the wind speed v in miles per hour 
// and the temperature t in Fahrenheit. Three formulas are used, depending on the 
// wind speed:  
// if (0 <= v <= 4) then WCI = t  
// if (v >=45) then WCI = 1.6t - 55  
// otherwise, WCI = 91.4 + (91.4 - t)(0.0203v - 0.304(v)1/2 - 0.474).  
// Write a program that can calculate the wind chill index.

#include <stdio.h>
#include <math.h>

double calculateWCI(double v, double t) {
    double WCI;
    if (v >= 0 && v <= 4) {
        WCI = t;
    } else if (v >= 45) {
        WCI = 1.6 * t - 55;
    } else {
        WCI = 91.4 + (91.4 - t) * (0.0203 * v - 0.304 * sqrt(v) - 0.474);
    }
    return WCI;
}

int main() {
    double v, t;
    printf("Enter wind speed: ");
    scanf("%lf", &v);
    printf("Enter temperature: ");
    scanf("%lf", &t);

    double WCI = calculateWCI(v, t);
    printf("The Wind Chill Index is: %.2f\n", WCI);
    return 0;
}
