/***************************************************************** 
[Modulatiry]
Modules
Mulitple source Files
Separating our functions
    1. header file: contains function prototypes for all functions. (.h)
    2. source file: contains function definitions, statements to include the header (.c)
    3. main file: contains main() function (.c)

Note!! compiling: gcc source1.c source2.c ... programmain.c
***************************************************************/
#include <stdio.h>
#include "Book_Code4.h"

double volumeOfSphere(double radius){
    return 4.0/3 * 3.14519 * radius * radius * radius;
}

double surfaceAreaOfSphere(double radius){
    return 4 * 3.14159 * radius * radius;
}

double getRadius(int sphereNumber){
    double radius;
    printf("Please enter the radias of sphere # %d: ", sphereNumber);
    scanf("%lf", &radius);
    return radius;
}