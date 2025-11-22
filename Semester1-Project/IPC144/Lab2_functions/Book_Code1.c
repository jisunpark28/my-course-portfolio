/******************************************
Sphere

note: int/int = int  ==> float/int = float
******************************************/
#include <stdio.h>
int main(void)
{
    double const pi = 3.14159;
    double volume ;
    double radius ;
    double area;

    printf("Please enter the radius of the sphere: ");
    scanf("%lf", &radius);
    volume = 4.0/3 * pi * radius * radius * radius;
    printf("The volume of the Sphere is %.2lf", volume);

    return 0;
}