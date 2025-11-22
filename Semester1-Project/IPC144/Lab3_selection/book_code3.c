/*
children: 12 and under - free
youth: 13 to 19 inclusive - $2.40
adults: - $3.35
seniors: 65 or older - $2.30


Selection - Alternative
    1. Explicit Branching
        if-else (참이면 A, 거짓이면 B)
    2. Default & Override
        if (일단 Default value 세팅, 만약 조건이 참이면 값을 덮어 씀 )
    3. mutually exclusive condiitons
        if-else if

*/

#include <stdio.h>
#include "book_code.h"

int getAge(){
    int age;
    printf("Please enter the age of the rider: ");
    scanf("%d", &age);
    return age;
}

double calculateFare(int age){
    double fare;
    if(age < 12){
            fare = 0;
    }
    else if (age >= 13 && age <= 19){
            fare = 2.40;
    }
    else if (age > 65){
            fare = 2.30;
    }
    else{
            fare = 3.35;
    }
    return fare;
}

void printResult(int age, double fare){
    printf("Rider of age %d must pay a fare of $%.2lf\n", age, fare);
}