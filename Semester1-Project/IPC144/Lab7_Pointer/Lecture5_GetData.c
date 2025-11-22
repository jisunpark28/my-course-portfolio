/******************************************
Problem
Create the following program

Create a function called 
getData that has to return 
the following information about 
a student(not a struct)

id, name, age and mark

Use a main function to 
1. obtain data
2. modify data
3. display data

******************************************/


#define _CRT_SECURE_NO_WARNING
#include <stdio.h>

void getData(int*, char[], int*, double*); //array는 point 필요없음

void getData(int* id, char name[], int* age, double* mark){
    printf("Enter Student ID: ");
    scanf("%d%*c", &(*id));
    printf("Enter Student Name: ");
    scanf("%30[^\n]%*c", name);
    printf("Enter Student Age: ");
    scanf("%d%*c", &(*age));
    printf("Enter Student Mark: ");
    scanf("%lf%*c", &(*mark));

}

int main(){
    int id;
    char name[31];
    int age;
    double mark;
    getData(&id, name, &age, &mark);

    return 0;
}