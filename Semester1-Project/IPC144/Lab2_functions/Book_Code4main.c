/***************************************************************** 
[Cohesion and coupling]

coupling: refers to the relationship of code(the degree of connectivity) between functions.


types of coupling
    No Coupling: Functions are completely independent.
    Message Coupling: Functions communicate through message passing.
    Data Coupling: Functions share data through parameters.
    Stamp Coupling: Functions share a composite data structure and use only a part of it.
    Control Coupling: One function controls the flow of another by passing it information on what to do.
    Common Coupling: Multiple functions share the same global data.
    Content Coupling: One function directly modifies or relies on the internal workings of another function.


Note! When we write functions we want them to be highly cohesive and loosely coupled.
***************************************************************/

#include <stdio.h>
#include "Book_Code4.h"

int main(void){

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