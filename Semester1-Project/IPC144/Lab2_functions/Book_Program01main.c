/***************************************************************** 
Q1: What is the difference between cohesion and coupling?

Cohesion describes the relationship of the code within a function
Coupling describes the relationship between functions.



Q2: Why is high cohesion desirable in a function?

A function that is highly cohesive is dedicated to a clear single objective. Every line of code is working towards the completion of that objective. It makes the function precise and understandable.



Q3: What is meant by the term loose coupling?

A function is loosely coupled if they are not dependent on each other. That is, each function can work on their own without needing to be paired to another function.
***************************************************************/

#include <stdio.h>
#include "Book_Program01.h"


int main(void){
    printf("Your height in centimeters is: %.2lf centimeters", metricHeight(5,7));
    return 0;
}