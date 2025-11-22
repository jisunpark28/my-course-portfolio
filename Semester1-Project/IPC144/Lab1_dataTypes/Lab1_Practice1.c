/*************************************************************************
Please enter a radius of a circle: 123.45
The diameter of the circle is 246.90
The circumference of the circle is 775.66
The area of the circle is 47877.53
**************************************************************************/

#define CRT_CECURE_NO_WARNING
#include <stdio.h>
int main(void)
{
    double const PI = 3.14159;
    double radius;
    double diameter;
    double circumference;
    double area;

    printf("Please enter a radius of a circle: ");
    scanf("%lf", &radius);

    diameter = 2 * radius;
    circumference = PI * diameter;
    area = PI * radius * radius;

    printf("The diameter of the circle is %.2lf\n", diameter);
    printf("The circumference of the circle is %.2lf\n", circumference);
    printf("The area of the circle is %.2lf\n", area);

    return 0;
}