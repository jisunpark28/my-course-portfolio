#define CRT_CECURE_NO_WARNING
#include <stdio.h>
int main(void)
{
    double tempC;
    double tempF;
    
    printf("Please enter the temperature in Celsious: ");
    scanf("%lf", &tempC);

    tempF = 1.8 * tempC + 32;

    printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit", tempC, tempF);


    return 0;
}