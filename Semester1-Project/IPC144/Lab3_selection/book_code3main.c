#include <stdio.h>
#include "book_code.h"



int main(void){
    int age = getAge();
    double fare = calculateFare(age);
    printResult(age, fare);
}