/******************************************
Problem 3

Create another function display to display all the student 

information
Create a new program to modify problem 2, this time using structs.

Introduce a struct Student and use that to obtain data, modify data 

and display data with the help of pointers
******************************************/


#define _CRT_SECURE_NO_WARNING
#include <stdio.h>

void getData(int*, char[], int*, double*); //array는 point 필요없음
void modifyData(int*, double*);
void display(int*, char[], int*, double*);

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
void modifyData(int* id, double* mark){
    printf("Enter New Student ID: ");
    scanf("%d%*c", &(*id));
    printf("Enter New Student Mark: ");
    scanf("%lf%*c", &(*mark));
}
void display(int* id, char name[], int* age, double* mark){
    printf("ID: %d\tName: %s\tAge: %d\tMark: %.2lf\n", *id, name, *age,*mark);  
}
int main(){
    int id;
    char name[31];
    int age;
    double mark;
    getData(&id, name, &age, &mark);
    display(&id, name, &age, &mark);
    modifyData(&id, &mark);
    display(&id, name, &age, &mark);
    return 0;
}