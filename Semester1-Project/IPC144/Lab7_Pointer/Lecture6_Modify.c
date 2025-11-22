/******************************************
Problem
Create another function called modifyData
that receives an id and mark and both have to be 
modified from user input. The modified data should be 
be available in main
******************************************/


#define _CRT_SECURE_NO_WARNING
#include <stdio.h>

void getData(int*, char[], int*, double*); //array는 point 필요없음
void modifyData(int*, double*);

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
int main(){
    int id;
    char name[31];
    int age;
    double mark;
    getData(&id, name, &age, &mark);
    modifyData(&id, &mark);

    return 0;
}