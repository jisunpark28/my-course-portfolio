/***************************************************************** 
[Function - 3 steps]
Function declaration: a function prototype, can skip the names of the parameters in the parameter list.
Function definition:what the functions do.
Function call: you call it by its name and pass in the required arguments
        
***************************************************************/
#include <stdio.h>

// function prototypes
double volumeOfSphere(double radius);
double surfaceAreaOfSphere(double radius);
double getRadius(int sphereNumber);

int main(void)
{

    double radius;
    double totalVolume;
    double totalArea;

    radius = getRadius(1);
    totalVolume = volumeOfSphere(radius);
    totalArea = surfaceAreaOfSphere(radius);

    radius = getRadius(2);
    totalVolume += volumeOfSphere(radius);
    totalArea += surfaceAreaOfSphere(radius);

    radius = getRadius(3);
    totalVolume += volumeOfSphere(radius);
    totalArea += surfaceAreaOfSphere(radius);

    printf("Total volume = %.2lf\n", totalVolume);
    printf("Total surface area = %.2lf\n", totalArea);
    return 0;
}

//function definitions:

double volumeOfSphere(double radius)
{
    return 4.0/3 * 3.14159 * radius * radius * radius;
}

double surfaceAreaOfSphere(double radius)
{
    return 4 * 3.14159 * radius * radius;
}

double getRadius(int sphereNumber)
{
    double radius;
    printf("Please enter the radius of sphere # %d: ",sphereNumber);
    scanf("%lf",&radius);
    return radius;
}